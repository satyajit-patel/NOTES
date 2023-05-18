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

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
class Solution {
public:
    int height(TreeNode* root) {
    // base case
    if(!root) return 0;
    
    // recursive case
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // store and return
    int ans = std::max(leftHeight, rightHeight) + 1;
    return ans;
    }

    int maxDepth(TreeNode* root) {
        return height(root);
    }
};