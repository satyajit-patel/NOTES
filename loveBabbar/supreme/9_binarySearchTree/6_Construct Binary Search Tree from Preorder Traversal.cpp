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
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/ 
class Solution {
public:
    TreeNode* built(int& i, int N, vector<int>& A, int mini, int maxi) {
        // base case
        if(i >= N) return NULL;

        // recursive case
        TreeNode* newNode = NULL;
        if(A[i]>mini && A[i]<maxi) {
            newNode = new TreeNode(A[i++]);
            newNode->left  = built(i, N, A, mini, newNode->val);
            newNode->right = built(i, N, A, newNode->val, maxi);
        }
        return newNode;
    }
   
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int N = preorder.size(), mini = INT_MIN, maxi = INT_MAX, i = 0;
        return built(i, N, preorder, mini, maxi);
    }
};