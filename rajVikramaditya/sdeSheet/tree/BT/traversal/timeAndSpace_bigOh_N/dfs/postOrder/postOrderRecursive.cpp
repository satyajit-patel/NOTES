/**
 * Definition for a binary tree node.
 https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/
 * struct TreeNode {
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
    void postOrder(TreeNode* node, vector<int> &ans) {
        if(node == NULL) return;
        
        postOrder(node->left, ans);
        postOrder(node->right, ans);
        ans.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        postOrder(root, ans);
        return ans;
    }
};