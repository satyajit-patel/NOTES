/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
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
#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vvi ans;
        vi level;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};