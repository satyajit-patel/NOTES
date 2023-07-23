/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL) return NULL;
        if(root == p) return p;
        if(root == q) return q;

        // recursive case
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        // calculate and return
        if(leftAns == NULL && rightAns == NULL) return NULL;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        else if(rightAns == NULL && leftAns != NULL) return leftAns;
        else return root;
    }
};