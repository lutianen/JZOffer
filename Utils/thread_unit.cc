#include <chrono>
#include <condition_variable>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

class ThreadPool {
public:
    ~ThreadPool() {
        for (auto& th : pool_) th.join();
    }

    void pushBack(std::thread thr) { pool_.push_back(std::move(thr)); }

private:
    std::vector<std::thread> pool_;
};

ThreadPool g_thread_pool;

void download(const std::string& str) {
    for (size_t i = 0; i <= 10; ++i) {
        printf("%s downloading .. %zu \% \r\n", str.c_str(), i * 10);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void func() {
    std::thread t([]() { download("Lute.zip"); });

    // 移交控制权到全局的 pool 中，使得 t 的生命周期得以延长
    g_thread_pool.pushBack(std::move(t));
}

template <typename T>
class MTQueue {
public:
    void push(T val) {
        std::unique_lock<std::mutex> lock(mtx_);
        vec_.push_back(std::move(val));
        cv_.notify_one();
    }

    void pushMany(std::initializer_list<T> vals) {
        std::unique_lock<std::mutex> lock(mtx_);
        std::copy(std::move_iterator<decltype(vals.begin())>(vals.begin()),
                  std::move_iterator<decltype(vals.end())>(vals.end()),
                  std::back_insert_iterator<std::vector<T>>(vec_));
        cv_.notify_all();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this]() { return !vec_.empty(); });
        T temp = std::move(vec_.back());
        vec_.pop_back();
        return temp;
    }

    std::pair<T, std::mutex> popHold() {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this]() { return !vec_.empty(); });
        T ret = std::move(vec_.back());
        vec_.pop_back();
        return std::pair<T, std::mutex>(std::move(ret), std::move(lock));
    }

private:
    std::condition_variable cv_;
    std::mutex mtx_;
    std::vector<T> vec_;
};

int main() {
    {
        // func();
    } {
        std::future<int> frc = std::async([&]() {
            download("Lute.tar.gz");
            return 12;
        });

        auto frc2 =
            std::async([]() { std::cout << "return void" << std::endl; });

        int rc = frc.get();
        frc2.get();

        std::cout << "frc = " << rc << std::endl;
    }

    {
        std::vector<int> arr;
        std::mutex mtx;
        std::thread t1([&]() {
            for (int i = 0; i < 1000; ++i) {
                std::unique_lock<std::mutex> lock(mtx);
                arr.push_back(1);
            }
        });

        std::thread t2([&]() {
            for (int i = 0; i < 1000; ++i) {
                std::unique_lock<std::mutex> u_lock(mtx);
                // std::unique_lock<std::mutex> lock(mtx, std::defer_lock);

                arr.push_back(2);
                // lock.unlock();
                printf("outside of lock\n");

                // lock.lock(); // 可以重新上锁
            }
        });

        t1.join();
        t2.join();
    }

    {
        std::recursive_mutex r_mtx;
        r_mtx.native_handle();
    }

    {
        MTQueue<int> foods;
        std::thread t1([&]() {
            for (int i = 0; i < 2; ++i) {
                auto food = foods.pop();
                std::cout << food << std::endl;
            }
        });

        std::thread t2([&]() {
            for (int i = 0; i < 2; ++i) {
                auto food = foods.pop();
                std::cout << food << std::endl;
            }
        });

        foods.push(12);
        foods.push(13);
        foods.pushMany({14, 15});

        t1.join();
        t2.join();
    }

    return 0;
}