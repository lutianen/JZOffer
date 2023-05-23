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

    // 优化版本：直接使用迭代器
    vector<vector<int>> threeSum2(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for(auto i = nums.begin(); i != std::prev(nums.end(), 2); ++i) {
            if (*i > 0) break;
            if (i > nums.begin() && *i == *(i - 1)) continue;

            auto j = std::next(i);
            auto k = std::prev(nums.end());
            while(j < k) {
                const int sum = *i + *j + *k;
                if (sum < 0) 
                    ++j;
                else if (sum > 0)
                    --k;
                else {
                    res.push_back({*i, *j, *k});
                    while (j < k && *j == *(j + 1)) j++;
                    while (j < k && *k == *(k - 1)) k--; 
                    ++j; --k;    
                } 
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

11. 搜索旋转排序数组

    ```C++
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
    
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            // 恰好找到，直接返回
            if (nums[mid] == target) return mid;
    
            // 区间划分
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n - 1])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
    
        return nums[left] == target ? left : -1;
    }
    ```

12. 有效的括号

    ```C++
    bool isValid(string s) {
        stack<char> stk;
        for (const char& c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else if (c == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                else
                    stk.pop();
            } else if (c == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                else
                    stk.pop();
            } else if (c == '}') {
                if (stk.empty() || stk.top() != '{')
                    return false;
                else
                    stk.pop();
            }
        }
    
        return stk.empty();
    }
    ```

13. 买卖股票的最佳时机

    ```C++
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
    
        int n = prices.size(), minv = prices[0];
        vector<int> d(n);
        d[0] = 0;
        for (int i = 1; i < n; ++i) {
            d[i] = max(d[i - 1], prices[i] - minv);
            minv = min(minv, prices[i]);
        }
    
        return d[n - 1];
    } 
    ```

14. 环形链表

    ```c++
    struct ListNode {
        int val;
        ListNode *next;
    
        ListNode(int v) : val(v), next(nullptr) {}
    };
    bool hasCycle(ListNode *head) {
        if (nullptr == head || nullptr == head->next) return false;
    
        ListNode *fast = head, *slow = head;
        while(true) {
            if (nullptr == fast || nullptr == fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
    
        return fast != nullptr;
    }
    ```

15. 合并两个有序数组

    ```c++
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            swap(nums1, nums2);
            return;
        }
    
        int idx1 = 0, idx2 = 0;
        vector<int> temp{};
        for (int i = 0; i < m + n; ++i) {
            int val = nums1[idx1] < nums2[idx2] ? nums1[idx1++] : nums2[idx2++];
            temp.push_back(val);
            if (idx1 == m || idx2 == n) break;
        }
        while (idx1 < m)
            temp.push_back(nums1[idx1++]);
        while (idx2 < n)
            temp.push_back(nums2[idx2++]);
        swap(temp, nums1);
    }
    
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            swap(nums1, nums2);
            return;
        }
        for (int i = 0; i < n; ++i)
            nums1[m + i] = nums2[i];
        std::sort(nums1.begin(), nums1.end());
    }
    ```

16. 岛屿数量

    ```c++
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
    
        int cnt = 0;
        std::function<void (int, int)> dfs = [&] (int x, int y) {
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] != '1') 
                return;
            grid[x][y] = '*';
            dfs(x - 1, y);
            dfs(x + 1, y);
            dfs(x, y - 1);
            dfs(x, y + 1);
        };
    
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        return cnt;
    }
    ```

17. 二叉树的锯齿形层序遍历

    ```c++
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(nullptr == root) return {};
    
        vector<vector<int>> res {};
        bool L2R = true;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()) {
            int k = que.size();
            vector<int> temp{};
            for (int i = 0; i < k; ++i) {
                TreeNode *cur = que.front();
                que.pop();
                temp.push_back(cur->val);
    
                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
    
            if (!L2R)
                reverse(temp.begin(), temp.end());
    
            res.push_back(temp);
            L2R = !L2R;
        }
    
        return res;
    }
    ```

18. 全排列

    ```c++
    vector<vector<int>> permute2(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {{nums[0]}};
        vector<vector<int>> res {};
        vector<int> path {};
        unordered_set<int> uset;
    
        function<void(int idx)> dfs = [&] (int idx) {
            if (idx >= n) {
                res.push_back(path);
                return;
            }
    
            for (int i = 0; i < n; ++i) {
                if (uset.find(nums[i]) != uset.end()) continue;
    
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(idx + 1);
                uset.erase(nums[i]);
                path.pop_back();
            }
        }; 
        dfs(0);
        return res;
    }
    
    void backTrace (int idx, const vector<int>& nums, int n,
                    vector<vector<int>>& res, vector<int>& path, 
                    unordered_set<int>& uset) {
        if (idx >= n) {
            res.push_back(path);
            return;
        }
    
        for (int i = 0; i < n; ++i) {
            if (uset.find(nums[i]) != uset.end()) continue;
    
            uset.insert(nums[i]); 
            path.push_back(nums[i]);
            backTrace(idx + 1, nums, n, res, path, uset);
            path.pop_back();
            uset.erase(nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {{nums[0]}};
        vector<vector<int>> res {};
        vector<int> path {};
        unordered_set<int> uset;
    
        backTrace(0, nums, n, res, path, uset);
        return res;
    }
    ```

19. 二叉树的最近公共祖先

    ```c++
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
    
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || p == root || q == root) return root;
    
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
        if (left == nullptr && right != nullptr) 
            return right;
        if (left != nullptr && right == nullptr)
            return left;
    
        return root;
    }
    ```

20. 螺旋矩阵

    ```c++
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
    
        vector<int> ret {}; 
        int top = 0, bot = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while(true) {
            // top
            for (int i = top, j = left; j <= right;){
                ret.push_back(matrix[i][j++]);
                if (j > right) {
                    top++;
                    break;
                }
            }
            if (top > bot) break;
    
            // right
            for (int i = top, j = right; i <= bot;) {
                ret.push_back(matrix[i++][j]);
                if (i > bot) {
                    right--;
                    break;
                }
            }
            if (left > right) break;
    
            // bottom
            for (int i = bot, j = right; j >= left;) {
                ret.push_back(matrix[i][j--]);
                if (j < left) {
                    bot--;
                    break;
                }
            }
            if (top > bot) break;
    
            // left
            for (int i = bot, j = left; i >= top;) {
                ret.push_back(matrix[i--][j]);
                if (i < top) {
                    left++;
                    break;
                }
            }
            if (left > right) break;
        } 
    
        return ret;
    }
    ```

21. 相交链表

    ```c++
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
    
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != cur2) {
            if (cur1 == nullptr)
                cur1 = headB;
            else 
                cur1 = cur1->next;
    
            if (cur2 == nullptr)
                cur2 = headA;
            else 
                cur2 = cur2->next;
        }
    
        return cur1 == nullptr ? nullptr : cur1;
    }
    ```

22. 反转链表 II

    ```c++
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (nullptr == head || left == right) return head;
    
        ListNode *dummy = new ListNode(-1, head), *p0 = dummy;
        for(int i = 0; i < left - 1; ++i) p0 = p0->next;
    
        ListNode *pre = nullptr, *cur = p0->next;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
    
        p0->next->next = cur;
        p0->next = pre;
    
        head = dummy->next;
        delete dummy;
        dummy = nullptr;
        return head;
    }
    ```

23. 字符串相加

    ```c++
    string addStrings(string num1, string num2) {
        int sn1 = num1.size(), sn2 = num2.size();
        int mn = std::max(sn1, sn2);
        if (sn1 < mn) {
            string temp;
            for (int i = 0; i < mn - sn1; ++i) temp += "0";
            num1 = temp + num1;
        } else {
            string temp;
            for (int i = 0; i < mn - sn2; ++i) temp += "0";
            num2 = temp + num2;
        }
    
        int count = 0;
        string res;
        for (int i = mn - 1; i >= 0; --i) {
            char v = count + (num1[i] - '0') + (num2[i] - '0');
            count = v / 10;
            res += std::to_string((v % 10));
        }
        if (count > 0)
            res += std::to_string(count);
    
        std::reverse(res.begin(), res.end());
        return res;
    }
    ```
