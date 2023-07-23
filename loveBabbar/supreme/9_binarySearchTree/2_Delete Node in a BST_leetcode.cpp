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

// https://leetcode.com/problems/delete-node-in-a-bst/description/
class Solution {
public:
    int maxVal(TreeNode* root) {
        while(root->right != NULL) root = root->right;
        return root->val;
    }

    TreeNode* deleteBST(TreeNode* root, int target) {
        if(!root) return NULL;
        if(target == root->val) {
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }
            else if(root->left && !root->right) {
                TreeNode* child = root->left;
                delete root;
                return child;
            }
            else if(!root->left && root->right) {
                TreeNode* child = root->right;
                delete root;
                return child;
            }
            else if(root->left && root->right) {
                int inOrderPre = maxVal(root->left);
                root->val = inOrderPre;
                root->left = deleteBST(root->left, inOrderPre);
                return root;
            }
        }
        else if(target < root->val) root->left = deleteBST(root->left, target);
        else if(target > root->val) root->right = deleteBST(root->right, target);
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        root = deleteBST(root, key);
        return root;
    }
};