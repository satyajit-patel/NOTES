/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// https://leetcode.com/problems/path-sum-ii/description/

#define vi  std::vector<int>
#define vvi std::vector<std::vector<int>>
class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    void f(TreeNode* root, int targetSum, int curSum, vi path, vvi& ans) {
        // base case
        if(!root) return;
        if(isLeaf(root)) {
            // 1 case pre work
            curSum += root->val;
            path.push_back(root->val);

            if(curSum == targetSum) ans.push_back(path);
            return;
        }

        // 1 case pre work
        curSum += root->val;
        path.push_back(root->val);

        // recursive case
        f(root->left, targetSum, curSum, path, ans);
        f(root->right, targetSum, curSum, path, ans);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> ans;
        f(root, targetSum, 0, {}, ans);
        return ans;
    }
};