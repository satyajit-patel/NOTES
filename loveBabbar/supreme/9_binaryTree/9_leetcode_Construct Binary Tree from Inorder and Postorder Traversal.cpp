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
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/ 
class Solution {
public:
    TreeNode* f(map<int, int>& in, vector<int>& post, int inStart, int inEnd, int& postEnd) {
        // base case
        if(postEnd < 0) return NULL;
        if(inStart > inEnd) return NULL;

        // 1 case pre work
        int ele = post[postEnd--];
        TreeNode* newNode = new TreeNode(ele);
        int mid = in[ele];

        // recursive case
        newNode->right = f(in, post, mid+1, inEnd, postEnd);
        newNode->left = f(in, post, inStart, mid-1, postEnd);

        // calculate and return
        return newNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> in;
        for(int i=0; i<inorder.size(); i++) in[inorder[i]] = i;
        int postEnd = postorder.size()-1;
        return f(in, postorder, 0, inorder.size()-1, postEnd);
    }
};