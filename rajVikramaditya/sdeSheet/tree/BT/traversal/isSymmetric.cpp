/**
 * Definition for a binary tree node.
 * struct TreeNode {
       https://leetcode.com/problems/symmetric-tree/submissions/
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isIt(TreeNode* lRoot, TreeNode* rRoot) {
        if(!lRoot || !rRoot) return lRoot == rRoot;
        return lRoot->val == rRoot->val && isIt(lRoot->left, rRoot->right) && isIt(lRoot->right, rRoot->left);
    }
public:
    bool isSymmetric(TreeNode* root) { //check for mirror image
        return !root || isIt(root->left, root->right);
    }
};