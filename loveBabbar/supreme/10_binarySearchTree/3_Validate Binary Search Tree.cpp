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

 // https://leetcode.com/problems/validate-binary-search-tree/description/
class Solution {
public:
    void getInOrder(std::vector<int>& inOrder, TreeNode* root) {
        // base case
        if(!root) return;

        // recursive case
        getInOrder(inOrder, root->left);

        // 1 case in work
        inOrder.push_back(root->val);

        getInOrder(inOrder, root->right);
    }

    bool isValidBST(TreeNode* root) {
        std::vector<int> inOrder;
        getInOrder(inOrder, root);

        // // check for duplicate element
        // std::set<int> st;
        // for(auto &it : inOrder) st.insert(it);
        // if(st.size() != inOrder.size()) return false;

        // if(std::is_sorted(inOrder.begin(), inOrder.end())) return true;
        // return false;

        for(int i=0; i<inOrder.size()-1; i++) if(inOrder[i] >= inOrder[i+1]) return false;
        return true;
    }
};