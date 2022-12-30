/**
 * Definition for binary tree
 https://www.interviewbit.com/problems/path-to-given-node/
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool getPath(TreeNode* root, int node, vector<int> &ans) {
    if(!root) return false;
    
    ans.push_back(root->val);
    if(root->val == node) return true;
    if(getPath(root->left, node, ans) || getPath(root->right, node, ans)) return true;
    ans.pop_back();
    return false;
} 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(!A) return ans;
    getPath(A, B, ans);
    return ans;
}