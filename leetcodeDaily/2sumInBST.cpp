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

//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
class Solution {
public:
    void postOrder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;
        
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    } 
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        postOrder(root, ans);
        
        sort(ans.begin(), ans.end());
        int low = 0, high = ans.size()-1;
        while(low < high) {
            int twoSum = ans[low] + ans[high];
            if(twoSum < k) low++;
            else if(twoSum > k) high--;
            else return true;
        }
        return false;
    }
};