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

24. 最长递增子序列

    ```c++
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        // d[i], 表示以 nums[i] 结尾的最长递增子序列长度
        vector<int> d(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if(nums[j] < nums[i])
                    d[i] = std::max(d[i], d[j] + 1);
            }
        }

        return *std::max_element(d.begin(), d.end());
    }
    ```

25. 环形链表 II

    ```c++
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int v) : val(v), next(nullptr) {}
    };

    ListNode *detectCycle(ListNode *head) {
        if (nullptr == head) return head;

        ListNode *fast = head, *slow = head;
        while(true) {
            if (fast == nullptr || fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        // Don't exist cycle
        if (nullptr == fast) return nullptr;

        // Exist Cycle
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
    ```

26. 接雨水

    ```c++
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        // perfix[i]，表示比 height[0 ... i] 中最高的，即前缀最大值
        // suffix[i]，表示比 height[i ... n-1] 中最高的，即后缀最大值
        vector<int> prefix(n);
        vector<int> suffix(n);

        // 求解前缀最大值、后缀最大值
        int temp = INT_MIN;
        for (int i = 0; i < n; ++i) {
            temp = std::max(temp, height[i]);
            prefix[i] = temp; 
        }
        temp = INT_MIN; 
        for (int i = n - 1; i >= 0; --i) {
            temp = std::max(temp, height[i]);
            suffix[i] = temp; 
        }

        // 根据前缀最大值、后缀最大值以及当前柱子高度，求解当前列所能接取的雨水
        int sum = 0;
        for (int i = 0; i < n; ++i) 
            sum += (std::min(prefix[i], suffix[i]) - height[i]);
        
        return sum;
    }
    ```

27. 重排链表

    ```c++
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    void reorderList(ListNode* head) {
        if (head == nullptr) return;

        std::deque<ListNode*> dq;
        ListNode *cur = head;

        while(nullptr != cur) {
            dq.push_back(cur);
            cur = cur->next;
        }

        bool flagFront = false;
        cur = dq.front();
        dq.pop_front();
        while(!dq.empty()) {
            if (flagFront) {
                cur->next = dq.front();
                dq.pop_front();
            } else {
                cur->next = dq.back();
                dq.pop_back();
            }

            flagFront = !flagFront;
            cur = cur->next;
        }
        cur->next = nullptr;
    }
    ```

28. 二叉树中的最大路径和

    ```c++
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
        TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
    };

    class Solution {
    public:
        int ret = INT_MIN;
        int maxPathSum(TreeNode* root) {
            dfs(root);
            return ret;
        }

    private:
        int dfs(TreeNode* root) {
            if (nullptr == root) return 0;

            // 左右子树的最大路径和，必须大于零才能加入当前路径
            int left = std::max(0, dfs(root->left));
            int right = std::max(0, dfs(root->right));

            // 记录当前路径最值
            ret = std::max(ret, root->val + left + right);
            // 选择一条路径和较大的路径
            return std::max(left, right) + root->val;
        }
    };
    ```

29. 二叉树的中序遍历

    ```c++
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
        TreeNode(int v, TreeNode* le, TreeNode* ri) : val(v), left(le), right(ri) {}
    };

    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> vec{};
            inorderTraversal(root, vec);
            return vec;
        }

    private:
        void inorderTraversal(TreeNode* root, vector<int>& vec) {
            if (root == nullptr) return;

            inorderTraversal(root->left, vec);
            vec.push_back(root->val);
            inorderTraversal(root->right, vec);
        }
    };
    ```

30. 用栈实现队列

    ```c++
    class MyQueue {
    private:
        std::stack<int> helper_;
        std::stack<int> queue_;

    public:
        MyQueue() : helper_(), queue_() {}

        void push(int x) {
            if (queue_.empty()) {
                queue_.push(x);
            } else {
                while (!queue_.empty()) {
                    helper_.push(queue_.top());
                    queue_.pop();
                }

                queue_.push(x);
                while (!helper_.empty()) {
                    queue_.push(helper_.top());
                    helper_.pop();
                }
            }
        }

        int pop() {
            int res = -1;
            if (!queue_.empty()) {
                res = queue_.top();
                queue_.pop();
            }

            return res;
        }

        int peek() {
            if (!queue_.empty()) {
                return queue_.top();
            }

            return -1;
        }

        bool empty() { return queue_.empty(); }
    };
    ```

31. 删除链表中倒数第 N 个节点

    ```c++
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) { std::cout << __FUNCTION__ << std::endl; }

        ~ListNode() { std::cout << __FUNCTION__ << std::endl; }
    };

    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (head == nullptr) return head;

            int len = 0;
            ListNode* cur = head;
            while (cur != nullptr) {
                cur = cur->next;
                ++len;
            }

            // 使用 dummy 节点，防止删除头节点导致异常
            std::unique_ptr<ListNode> dummy(new ListNode(-1, head));
            cur = dummy.get();
            for (int i = 0; i <= len - n; ++i) {
                if (i == len - n) {
                    ListNode* toDelNode = cur->next;
                    cur->next = cur->next->next;

                    delete toDelNode;
                    toDelNode = nullptr;

                    break;
                }
                cur = cur->next;
            }
            // 更正头节点
            head = dummy->next;
            return head;
        }
    };
    ```

32. 编辑距离

    ```C++
    int minDistance(string word1, string word2) {
        if (word2.empty() && word1.empty()) return 0;
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();

        int n1 = word1.size(), n2 = word2.size();

        /*
           d[i][j]，表示将 word1[0 .. i - 1] 转换成 word2[0 .. j - 1] 所使用的最少操作数
           d[0][0]，表示从 "" 变换到 "" 所使用的最少操作数，显然为 0
           d[0][j]，表示从 "" 变换到 word2[j - 1] 所使用的最少操作数，显然为 j
           d[i][0]，表示从 word1[i - 1] 变换到 "" 所使用的最少操作数，显然为 i
        */
        vector<vector<int>> d(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n2; ++i) d[0][i] = i;
        for (int i = 1; i <= n1; ++i) d[i][0] = i;

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    d[i][j] = d[i - 1][j - 1];
                else {
                    d[i][j] = std::min(std::min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
                }
            }
        }

        return d[n1][n2];
    }
    ```

33. 二分查找

    ```C++
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = ((right - left) >> 1) + left;
            if (nums[middle] < target)
                left = middle + 1;
            else if (nums[middle] > target)
                right = middle - 1;
            else
                return middle;
        }

        return -1;
    }
    ```

34. 找两个正序数组的中位数

    ```c++
    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int> temp = merge(nums1, nums2);
            int n = nums1.size() + nums2.size();
            return (n & 1) == 1 ? temp[n / 2] : (temp[n / 2 - 1] + temp[n / 2]) * 0.5;
        }

    private:
        vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
            vector<int> temp;
            auto it1 = nums1.begin(), it2 = nums2.begin();
            while (it1 != nums1.end() && it2 != nums2.end()) {
                if (*it1 > *it2) {
                    temp.push_back(*it2);
                    ++it2;
                } else {
                    temp.push_back(*it1);
                    ++it1;
                }
            }

            while (it1 != nums1.end()) {
                temp.push_back(*it1);
                ++it1;
            }
            while (it2 != nums2.end()) {
                temp.push_back(*it2);
                ++it2;
            }

            return temp;
        }
    };
    ```

35. 合并区间

    ```c++
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int st = INT_MAX, ed = INT_MIN;
        vector<vector<int>> res{};
        for (size_t i = 0; i < intervals.size(); ++i) {
            st = min(st, intervals[i][0]);
            ed = max(ed, intervals[i][1]);
            if (i == intervals.size() - 1 || ed < intervals[i + 1][0]) {
                res.push_back({st, ed});
                if (i != intervals.size() - 1) st = intervals[i + 1][0];
            }
        }

        return res;
    }
    ```

36. 二叉树的右视图

    ```c++
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            if (nullptr == root) return {};

            // Level trace
            vector<int> res{};
            queue<TreeNode*> que;
            que.push(root);
            while (!que.empty()) {
                int k = que.size();
                for (int i = 0; i < k; ++i) {
                    TreeNode* cur = que.front();
                    que.pop();
                    // 最右侧节点
                    if (i == k - 1) res.push_back(cur->val);

                    if (cur->left != nullptr) que.push(cur->left);
                    if (cur->right != nullptr) que.push(cur->right);
                }
            }
            return res;
        }
    };
    ```

37. 删除排序链表中的重复元素 II

    ```c++
    struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
    };

    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (nullptr == head) return head;

            // ListNode *dummy = new ListNode(-1, head);
            std::unique_ptr<ListNode> dummy(new ListNode(-1, head));
            ListNode *pre = dummy.get(), *cur = head;
            while (nullptr != cur) {
                ListNode* nxt = cur->next;

                if (nxt != nullptr && cur->val == nxt->val) {
                    while (nxt != nullptr && cur->val == nxt->val) {
                        cur = nxt;
                        nxt = nxt->next;
                    }

                    pre->next = nxt;
                }

                // 当前值不重复
                if (cur == pre->next) {
                    pre = cur;
                } else if (cur == pre->next && nxt == nullptr) /* 当前值不重复，且位于最后一个节点 */ {
                    pre->next = cur;
                }
                cur = nxt;
            }

            head = dummy->next;
            return head;
        }
    };
    ```

38. 爬楼梯

    ```c++
    int climbStairs(int n) {
        if (n <= 1) return n;

        // d[i] 表示到达第 i 阶台阶的不同方法数量
        // d[i] = d[i - 1] + d[i - 2]
        vector<int> d(n + 1);
        d[1] = 1;
        d[2] = 2;

        for (int i = 3; i <= n; ++i) d[i] = d[i - 1] + d[i - 2];

        return d[n];
    }
    ```

39. 排序链表

    ```c++
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (head == nullptr) return head;

            vector<ListNode*> vec{};
            ListNode* cur = head;
            while (nullptr != cur) {
                vec.push_back(cur);
                cur = cur->next;
            }
            sort(vec.begin(), vec.end(), [&](ListNode* pa, ListNode* pb) { return pa->val > pb->val; });

            auto iter = vec.begin();
            head = cur = *iter;
            for (++iter; iter != vec.end(); ++iter) {
                cur->next = *iter;
                cur = cur->next;
            }
            cur->next = nullptr;

            return head;
        }

        ListNode* sortList2(ListNode* head) { return mergeSort(head); }

    private:
        ListNode* getMiddleNode(ListNode* head) {
            auto slow = head, fast = head;
            while (fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        ListNode* mergeTowList(ListNode* l1, ListNode* l2) {
            std::unique_ptr<ListNode> dummy(new ListNode());
            ListNode* cur = dummy.get();
            while (l1 && l2) {
                if (l1->val <= l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                } else {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            cur->next = l1 ? l1 : l2;
            return dummy->next;
        }

        ListNode* mergeSort(ListNode* head) {
            if (!head || !head->next) return head;
            ListNode* mid = getMiddleNode(head);
            ListNode* l1 = head;
            ListNode* l2 = mid->next;
            mid->next = nullptr;
            l1 = mergeSort(l1);
            l2 = mergeSort(l2);
            return mergeTowList(l1, l2);
        }
    };

    ```

40. x 的平方根

    ```c++
    // 暴力查找
    // 时间复杂度 O(x*0.5)
    int mySqrt(int x) {
        if (x == 1) return 1;

        size_t X = x;
        int res = 0;
        for (size_t i = 0; i * i <= X; ++i) {
            res = i;
        }
        return res;
    }

    // 二分法
    // 时间复杂度 O(log n)
    int mySqrt2(int x) {
        size_t left = 0, right = x;
        int res = left;
        while(left <= right) {
            size_t mid = left + ((right - left) >> 1);
            if (mid * mid < x) {
                left = mid + 1;
                res = mid;
            } else if (mid * mid > x) {
                right = mid - 1;
            } else {
                res = mid;
                break;
            }
        }
        return res;
    }
    ```

41. 两数相加

    ```c++
    struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(-1), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* p) : val(x), next(p) {}
    };

    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            if (l1 == nullptr) return l2;
            if (l2 == nullptr) return l1;

            int count = 0;
            ListNode *head = nullptr, *cur = head;

            while (true) {
                if (l1 == nullptr && l2 == nullptr) break;

                int sum = 0, rem = 0;
                if (l1 == nullptr)
                    sum = count + l2->val;
                else if (l2 == nullptr)
                    sum = count + l1->val;
                else
                    sum = count + l1->val + l2->val;

                count = sum / 10;
                rem = sum % 10;
                if (head == nullptr) {
                    head = new ListNode(rem);
                    cur = head;
                } else {
                    cur->next = new ListNode(rem);
                    cur = cur->next;
                }
                l1 = l1 == nullptr ? nullptr : l1->next;
                l2 = l2 == nullptr ? nullptr : l2->next;
            }
            if (count != 0) cur->next = new ListNode(count);

            return head;
        }
    };
    ```

42. 括号生成

    ```c++
    class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            if (n <= 0) return {};

            vector<string> res;
            string curStr;
            dfs(curStr, n, n, res);
            return res;
        }

    private:
        void dfs(string& curStr, int left, int right, vector<string>& res) {
            if (left == 0 && right == 0) {
                res.push_back(curStr);
                return;
            }

            if (left > right) return;

            if (left > 0) {
                curStr.push_back('(');
                dfs(curStr, left - 1, right, res);
                curStr.pop_back();
            }

            if (right > 0) {
                curStr.push_back(')');
                dfs(curStr, left, right - 1, res);
                curStr.pop_back();
            }
        }
    };
    ```

43. 最长公共子序列

    ```c++
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;

        int m = text1.size(), n = text2.size();
        // d[i][j] 表示 s1[0...i - 1] 与 s2[0...j - 1] 的最长公共子序列长度
        // d[i][j] = s1[i] == s2[j] ? d[i - 1][j - 1] + 1 : max(d[i - 1][j] or d[i][j - 1])
        // len = max(len, d[i][j])
        vector<vector<int>> d(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) d[i][0] = 0;
        for (int i = 0; i <= n; ++i) d[0][i] = 0;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    d[i][j] = d[i - 1][j - 1] + 1;
                } else {
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
                }
            }
        }

        return d[m][n];
    }
    ```

44. 字符串转换整数 (atoi)

    ```c++
    class Solution {
    public:
        int myAtoi(std::string& s) {
            if (s.empty()) return 0;

            size_t cur = 0;
            while (s[cur] == ' ') ++cur;

            bool sign = true;
            if (s[cur] == '+' || s[cur] == '-') {
                sign = s[cur] == '-' ? false : true;
                ++cur;
            }

            long long res = 0;
            while (cur < s.size() && isDigit(s[cur])) {
                int num = s[cur++] - '0';

                if (res >= LONG_LONG_MAX / 10) break;
                res = res * 10 + num;
            }

            if (!sign)
                res = -res < INT_MIN ? INT_MIN : -res;
            else
                res = res > INT_MAX ? INT_MAX : res;

            return static_cast<int>(res);
        }

    private:
        bool isDigit(const char c) { return c >= '0' && c <= '9'; }
    };
    ```

45. 缺失的第一个正数

    ```c++
    class Solution {
    public:
        // 哈希实现
        // 空间复杂度 O(N), 时间复杂度 O(N)
        int firstMissingPositive(vector<int>& nums) {
            std::unordered_set<int> uset;
            for (const int num : nums) uset.insert(num);

            size_t i = 1;
            for (; i <= nums.size(); ++i)
                if (uset.find(i) == uset.end()) return i;

            return i;
        }

        // 原地哈希
        // 空间复杂度 O(1), 时间复杂度 O(N)
        int firstMissingPositive2(vector<int>& nums) {
            for (size_t i = 0; i < nums.size(); ++i) {
                while (nums[i] != i + 1) {
                    if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) break;

                    int idx = nums[i] - 1;
                    nums[i] = nums[idx];
                    nums[idx] = idx + 1;
                }
            }

            for (size_t i = 0; i < nums.size(); ++i)
                if (nums[i] != i + 1) return i + 1;

            return nums.size() + 1;
        }
    };
    ```

46. 链表中倒数第k个节点

    ```c++
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution {
    public:
        ListNode* getKthFromEnd(ListNode* head, int k) {
            if (head == nullptr) return head;

            ListNode* cur = head;
            int len = 0;
            while (nullptr != cur) {
                cur = cur->next;
                ++len;
            }

            cur = head;
            for (int i = 0; i < len - k; ++i) cur = cur->next;

            return cur;
        }
    };
    ```

47. 比较版本号

    ```c++
    class Solution {
    public:
        int compareVersion(string version1, string version2) {
            vector<string> vs1, vs2;
            getVers(vs1, version1);
            getVers(vs2, version2);

            if (vs1.size() != vs2.size()) {
                size_t len = vs1.size() < vs2.size() ? vs2.size() : vs1.size();
                while (vs1.size() < len) vs1.push_back("0");
                while (vs2.size() < len) vs2.push_back("0");
            }

            for (size_t i = 0; i < vs1.size(); ++i) {
                if (std::stoi(vs1[i]) < std::stoi(vs2[i]))
                    return -1;
                else if (std::stoi(vs1[i]) > std::stoi(vs2[i]))
                    return 1;
            }

            return 0;
        }

    private:
        void getVers(vector<string>& vs, const string& version) {
            if (version.empty()) return;

            size_t cur = 0;
            int st = 0, ed = 0;
            while (cur < version.size()) {
                if (version[cur] == '.' || cur == version.size() - 1) {
                    ed = version[cur] == '.' ? cur - 1 : cur;
                    vs.push_back(version.substr(st, ed - st + 1));
                    st = cur + 1;
                }
                ++cur;
            }
        }
    };
    ```

48. 最小栈

    ```cpp
    class MinStack {
    public:
        MinStack() {}

        void push(int val) {
            stk_.push(val);
            if (hlp_.empty())
                hlp_.push(val);
            else
                hlp_.push(val < hlp_.top() ? val : hlp_.top());
        }

        void pop() {
            if (!stk_.empty()) {
                stk_.pop();
                hlp_.pop();
            }
        }

        int top() {
            if (!stk_.empty()) return stk_.top();
            return -1;
        }

        int getMin() {
            if (!hlp_.empty()) return hlp_.top();
            return -1;
        }

    private:
        stack<int> stk_;
        stack<int> hlp_;
    };
    ```

49. 零钱兑换

    ```cpp
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        // d[i] 表示装满容量为 i 的背包，所需的最少硬币数量
        // d[i] = d[i - coins[j]] + 1;
        // NOTE 由于 amount + 1 是不可能达到的换取数量，故使其填充
        vector<int> d(amount + 1, amount + 1);
        d[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int j = coins.size() - 1; j >= 0; --j) {
                if (coins[j] <= i) d[i] = min(d[i], d[i - coins[j]] + 1);
            }
        }

        return d[amount] == amount + 1 ? -1 : d[amount];
    }
    ```

50. 子集

    ```cpp
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};

        vector<vector<int>> res;
        vector<int> path;

        // 回溯算法 - dfs
        std::function<void(int)> dfs = [&](size_t idx) -> void {
            res.push_back(path);
            if (idx >= nums.size()) {
                return;
            }

            for (size_t i = idx; i < nums.size(); ++i) {
                path.push_back(nums[i]);
                dfs(i + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return res;
    }
    ```

51. 字符串相乘

    ``` cpp
    class Solution {
    public:
        // 模拟 - 每一个数字和数字字符串相乘，然后结果相加
        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0") return "0";

            vector<string> tempVec;
            for (int i = num2.size() - 1; i >= 0; --i) {
                tempVec.push_back(intMulStr(num2[i] - '0', num1));
            }
            for (size_t i = 0; i < tempVec.size(); ++i) {
                for (int j = i; j > 0; --j) tempVec[i].push_back('0');
            }

            string res = tempVec[0];
            for (size_t i = 1; i < tempVec.size(); ++i) {
                res = addStrnumber(res, tempVec[i]);
            }
            return res;
        }

    private:
        string intMulStr(int x, string& str) {
            if (x == 0) return "0";

            string strCpy = str;
            std::reverse(strCpy.begin(), strCpy.end());
            int count = 0;
            string res;

            for (const auto& c : strCpy) {
                int temp = (x * (c - '0')) + count;
                count = temp / 10;
                res.append(std::to_string(temp % 10));
            }
            if (count != 0) res.append(std::to_string(count));

            std::reverse(res.begin(), res.end());
            return res;
        }

        string addStrnumber(string& num1, string& num2) {
            if (num1.empty()) return num2;
            if (num2.empty()) return num1;

            std::reverse(num1.begin(), num1.end());
            std::reverse(num2.begin(), num2.end());

            size_t n1 = num1.size(), n2 = num2.size();
            size_t len = std::max(n1, n2), count = 0;
            while (num1.size() < len) num1.push_back('0');
            while (num2.size() < len) num2.push_back('0');

            string res;
            for (size_t i = 0; i < len; ++i) {
                int temp = count + (num1[i] - '0') + (num2[i] - '0');
                res.append(std::to_string(temp % 10));
                count = temp / 10;
            }
            if (count != 0) res.append(std::to_string(count));

            std::reverse(res.begin(), res.end());
            return res;
        }
    };

    ```

52. 从前序与中序遍历序列构造二叉树

    ```cpp
    // Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right)
            : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.empty() || inorder.empty()) return nullptr;

            int val = preorder[0];
            TreeNode* root = new TreeNode(val);
            size_t i = 0;
            for (; i < inorder.size(); ++i) {
                if (inorder[i] == val) break;
            }

            vector<int> iLeft(inorder.begin(), inorder.begin() + i);
            vector<int> iRight(inorder.begin() + i + 1, inorder.end());
            size_t n = iLeft.size();
            vector<int> pLeft(preorder.begin() + 1, preorder.begin() + n + 1);
            vector<int> pRight(preorder.begin() + n + 1, preorder.end());

            root->left = buildTree(pLeft, iLeft);
            root->right = buildTree(pRight, iRight);

            return root;
        }
    };
    ```

53. 反转字符串中单词

    ```cpp
        string reverseWords(string s) {
        if (s.empty()) return "";

        size_t cur = 0;
        while (cur < s.size() && s[cur] == ' ') ++cur;

        size_t st = cur;
        // vector<string> strs;

        stack<string> stk;
        string ret;
        while (cur < s.size()) {
            while (cur < s.size() && s[cur] != ' ') cur++;
            // strs.push_back(s.substr(st, cur - st));
            stk.push(s.substr(st, cur - st));

            while (cur < s.size() && s[cur] == ' ') ++cur;
            st = cur;
        }

        // std::reverse(strs.begin(), strs.end());
        // auto iter = strs.begin();
        // string ret = *iter;
        // for (++iter; iter != strs.end(); ++iter) ret += " " + *iter;

        ret += stk.top();
        stk.pop();
        while (!stk.empty()) {
            ret += " " + stk.top();
            stk.pop();
        }
        return ret;
    }
    ```

54. 二叉树的前序遍历

    ```cpp
    struct TreeNode {
        int val_;
        TreeNode* left_;
        TreeNode* right_;

        TreeNode() : val_(0), left_(nullptr), right_(nullptr) {}
        TreeNode(int val) : val_(val), left_(nullptr), right_(nullptr) {}
        TreeNode(int val, TreeNode* left, TreeNode* right)
            : val_(val), left_(left), right_(right) {}
    };

    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            if (nullptr == root) return {};
            vector<int> res{};

            std::function<void(TreeNode*)> f = [&](TreeNode* root) {
                if (root == nullptr) return;

                res.push_back(root->val_);
                f(root->left_);
                f(root->right_);
            };

            f(root);

            return res;
        }
    };
    ```

55. 对称二叉树

    ```cpp
        bool isSymmetric(TreeNode* root) {
            if (root == nullptr) return true;

            std::function<bool(TreeNode*, TreeNode*)> f = [&](TreeNode* left,
                                                            TreeNode* right) {
                if (left == nullptr && right == nullptr) return true;
                if (left == nullptr || right == nullptr) return false;

                return left->val == right->val && f(left->left, right->right) &&
                    f(left->right, right->left);
            };
            return f(root->left, root->right);
        }    
    ```
