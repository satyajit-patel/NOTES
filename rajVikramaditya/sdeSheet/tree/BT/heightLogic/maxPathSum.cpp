/**
 * Definition for a binary tree node.
 * struct TreeNode {
       https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int height(TreeNode* root, int &maxi) {
        if(!root) return 0;
        
        //make sure we only take the +ve value into consideration
        int left = max(0, height(root->left, maxi));
        int right = max(0, height(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        height(root, maxi);
        return maxi;
    }
};