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
class Solution {
public:
    //go left left left .... untill NULL then come back
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        while(true) {
            if(root) {
                st.push(root);
                root = root->left;
            }
            else {
                if(st.empty()) break;
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};