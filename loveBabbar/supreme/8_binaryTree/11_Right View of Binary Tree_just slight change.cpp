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

 // https://leetcode.com/problems/binary-tree-right-side-view/description/
class Solution {
public:
    void f(TreeNode* root, int& level, std::vector<int>& rightView) {
        // base case
        if(!root) return;
        
        // 1 case pre work
        if(level == rightView.size()) rightView.push_back(root->val);
        level += 1;
        
        // recursive case
        f(root->right, level, rightView); // just change the order of calling
        f(root->left, level, rightView);
        
        // backtrack
        level -= 1;
    }

    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> rightView;
        int level = 0;
        f(root, level, rightView);
        return rightView;
    }
};