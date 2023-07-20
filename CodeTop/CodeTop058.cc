/**
 * @file CodeTop058.cc
 *
 * @brief 求根节点到叶节点数字之和
 *
 * @author Tian-en Lu >> https://github.com/lutianen
 * @copyright Copyright (c) 2023
 * For study and research only
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;

        vector<vector<int>> nums;
        vector<int> path;

        getNumbers(root, path, nums);
        auto temp = getInteger(nums);

        int ret = 0;
        while (!temp.empty()) {
            ret += temp.back();
            temp.pop_back();
        }

        return ret;
    }

private:
    void getNumbers(TreeNode* root, vector<int>& path,
                    vector<vector<int>>& nums) {
        if (root == nullptr) return;
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            nums.push_back(path);
        }

        getNumbers(root->left, path, nums);
        getNumbers(root->right, path, nums);
        path.pop_back();
    }

    vector<int> getInteger(vector<vector<int>>& nums) {
        vector<int> ret;
        for (vector<int> path : nums) {
            reverse(path.begin(), path.end());
            int num = 0;
            while (!path.empty()) {
                num = path.back() + num * 10;
                path.pop_back();
            }
            ret.push_back(num);
        }
        return ret;
    }
};

int main() {
    cout << " Tree .. " << endl;
    return 0;
}