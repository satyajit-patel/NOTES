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
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/ 
class Solution {
public:
    TreeNode* f(vector<int>& pre, map<int, int>& in, int& preStart, int inStart, int inEnd) {
        // base case
        if(preStart >= pre.size()) return NULL;
        if(inStart > inEnd) return NULL;

        // 1 case pre work
        int ele = pre[preStart++];
        TreeNode* newNode = new TreeNode(ele);
        int mid = in[ele];

        // recursive case
        newNode->left = f(pre, in, preStart, inStart, mid-1);
        newNode->right = f(pre, in, preStart, mid+1, inEnd);

        // calculate and return
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> in;
        for(int i=0; i<inorder.size(); i++) in[inorder[i]] = i;
        int preStart = 0;
        return f(preorder, in, preStart, 0, inorder.size()-1);
    }
};