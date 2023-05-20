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

7. 快速排序

    ``` C++
    class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            quickSort(nums, 0, nums.size() - 1);
            return nums;
        }

    private:
        void quickSort(vector<int>& nums, int left, int right) {
            if (left >= right) return;

            bool sorted = true;
            for (int i = left; i < right; i++) 
                if (nums[i] > nums[i+1]) sorted = false;
            if (sorted) return;

        std::swap(nums[right], nums[(rand() % (right - left + 1)) + left]);
        int i = left, j = right - 1;
        int povit = nums[right];

        while(i < j) {
            while(i <= j && nums[i] < povit) ++i;
            while(i <= j && nums[j] > povit) --j;
            if (i < j)
                std::swap(nums[i++], nums[j--]);
        }

        std::swap(nums[right], nums[i]);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
    };
    ```

8. 合并两个有序链表

    ```C++
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (nullptr == list1) return list2;        
        if (nullptr == list2) return list1;        

        bool flag = list1->val < list2->val ? true : false;
        ListNode *head = nullptr;
        if (flag) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode *cur = head;
        while(list1 != nullptr && list2 != nullptr) {
            flag = list1->val < list2->val ? true : false;
            if (flag) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }

            cur = cur->next;
        }
        if (list1 == nullptr) cur->next = list2;
        if (list2 == nullptr) cur->next = list1;

        return head;
    }
    ```

9. 二叉树的层序遍历

    ```C++
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(nullptr == root) return {};
        vector<vector<int>> res;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int k = que.size();
            vector<int> temp;
            for (int i = 0; i < k; ++i) {
                auto cur = que.front();
                temp.push_back(cur->val);
                que.pop();

                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
            res.push_back(temp);
        }

        return res;
    }
    ```

10. 最长回文子串

    ```C++
    string longestPalindrome(string s) {
        if (s.empty() || s.size() < 2) return s;

        // stIdx - 回文串的起始下标
        int n = s.size(), stIdx = 0, len = 1;
        // d[i][j]，表示s[i ... j]是否是回文子串
        std::vector<std::vector<bool>> d(n, std::vector<bool>(n));
        d[0][0] = true;
        
        // 动态规划
        for (int r = 1; r < n; ++r) {
            for (int l = 0; l < r; ++l) {
                // d[l][r] = s[l] == s[r] && (r - l <= 2 || d[l + 1][r - 1])
                if (s[l] == s[r] && (r - l <= 2 || d[l + 1][r - 1])) {
                    d[l][r] = true;
                    // update len
                    if (r - l + 1 > len) {
                        len = r - l + 1;
                        stIdx = l;
                    }
                }
            }
        }

        return s.substr(stIdx, len);
    }
    ```
