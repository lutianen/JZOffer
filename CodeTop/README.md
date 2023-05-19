# [CodeTop](https://codetop.cc)

1. 无重复字符的最长子串

    ``` c++
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_set<char> uset{};
        int sn = s.size();
        int left = 0, right = 0, maxLen = INT_MIN;
        while(right < sn) {
            while(uset.find(s[right]) != uset.end()) {
                uset.erase(s[left++]);
            }

            uset.insert(s[right]);
            maxLen = max(maxLen, (right++) - left + 1);
        }

        return maxLen;
    }
    ```

2. 反转链表

    ```c++
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head) return head;

        ListNode *pre = nullptr, *cur = head;
        while(cur != nullptr) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
    ```

3. LRU 缓存机制

    ``` C++
    /**
    * @brief LUR 缓存
    */

    #include <iostream>
    #include <unordered_map>
    #include <list>
    #include <utility>

    using std::pair;
    using std::list;
    using std::unordered_map;
    using std::cout;
    using std::endl;

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
                if (cache_.size() == capacity_) {
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
        list<pair<int, int>> cache_;
        unordered_map<int, list<pair<int, int>>::iterator> kv_;
    };
    ```

4. 数组中的第K个最大元素

    ```C++
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> 
                pque(nums.begin(), nums.begin() + k);

        for (size_t i = k; i < nums.size(); ++i) {
            if (nums[i] > pque.top()) {
                pque.pop();
                pque.push(nums[i]);
            }
        }

        return pque.top(); 
    }
    ```
5. 三数之和

    ```C++
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> res {};
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> temp{nums[i], nums[left], nums[right]};
                    res.emplace_back(temp);
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++; right--;
                } else if (sum < 0)
                    ++left;
                else 
                    --right;
            }
        }

        return res;
    }
    ```
6. 最大连续子数组和

    ```C++
    int maxSubArray(vector<int>& nums) {
        // d[i] 表示以 i 为结尾的 nums[i] 的最大连续子数组的和
        int n = nums.size();
        if(n <= 0) return -1;
        if(n == 1) return nums[0];

        vector<int> d(n);
        d[0] = nums[0];
        int maxv = d[0];
        for (int i = 1; i < n; ++i) {
            d[i] = max(nums[i], d[i - 1] + nums[i]);
            maxv = max(maxv, d[i]);
        }

        return maxv;
    }
    ```