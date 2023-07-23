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
 // https://leetcode.com/problems/path-sum-iii/description/
class Solution {
public:
    int ans = 0;
    void f(TreeNode* root, long long targetSum) {
        // base case
        if(!root) return;

        // work case
        if(targetSum == root->val) ++ans;

        // recursive case
        f(root->left, targetSum-root->val);
        f(root->right, targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root) {
            f(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};