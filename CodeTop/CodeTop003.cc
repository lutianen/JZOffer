/**
 * @brief LRU 缓存
 * @link https://leetcode.cn/problems/lru-cache
 */

#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::list;
using std::pair;
using std::unordered_map;

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (kv_.find(key) != kv_.end()) {
            auto kv = *kv_[key];
            cache_.erase(kv_[key]);
            cache_.push_front(kv);
            kv_[key] = cache_.begin();

            return kv.second;
        }

        return -1;
    }

    void put(int key, int value) {
        if (kv_.find(key) == kv_.end()) {
            if (cache_.size() == static_cast<size_t>(capacity_)) {
                kv_.erase(cache_.back().first);
                cache_.pop_back();
            }
        } else {
            cache_.erase(kv_[key]);
        }

        cache_.push_front({key, value});
        kv_[key] = cache_.begin();
    }

private:
    int capacity_;
    //        key, val
    list<pair<int, int>> cache_;
    //            key  iter
    unordered_map<int, list<pair<int, int>>::iterator> kv_;
};

int main() {
    LRUCache* lru = new LRUCache(2);
    lru->put(1, 1);
    lru->put(2, 2);
    cout << lru->get(1) << endl;
    lru->put(3, 3);
    cout << lru->get(2) << endl;
    lru->put(4, 4);
    cout << lru->get(1) << endl;
    cout << lru->get(3) << endl;
    cout << lru->get(4) << endl;

    return 0;
}