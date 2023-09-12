#include <chrono>
#include <condition_variable>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class ThreadPool {
public:
    ~ThreadPool() {
        for (auto& th : pool_) th.join();
    }

    void pushBack(thread thr) { pool_.push_back(std::move(thr)); }

private:
    vector<thread> pool_;
};

ThreadPool g_thread_pool;

void download(const string& str) {
    for (size_t i = 0; i <= 10; ++i) {
        printf("%s downloading .. %zu \% \r\n", str.c_str(), i * 10);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void func() {
    thread t([]() { download("Lute.zip"); });

    // 移交控制权到全局的 pool 中，使得 t 的生命周期得以延长
    g_thread_pool.pushBack(std::move(t));
}

int main() {
    // func();

    std::future<int> frc = std::async([&]() {
        download("Lute.tar.gz");
        return 12;
    });

    auto frc2 = std::async([]() { std::cout << "return void" << std::endl; });

    int rc = frc.get();
    frc2.get();

    std::cout << "frc = " << rc << std::endl;

    return 0;
}