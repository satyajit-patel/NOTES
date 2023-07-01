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
 // https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
class Node {
public: 
    int maxNode, minNode, maxSum;

    Node() {
        this->maxSum = 0;
        this->maxNode = INT_MIN;
        this->minNode = INT_MAX;
    }
};
class Solution {
public:
int ans;
    Node f(TreeNode* root) {
        // base case
        if(!root) return Node();

        // recursive case
        auto leftAns = f(root->left);
        auto rightAns = f(root->right);

        // 1 case post work
        Node node;
        if(root->val>leftAns.maxNode && root->val<rightAns.minNode) {
            node.maxSum = root->val + leftAns.maxSum + rightAns.maxSum;
            node.maxNode = std::max(rightAns.maxNode, root->val);
            node.minNode = std::min(leftAns.minNode, root->val);
        }
        else {
            node.maxSum = std::max(leftAns.maxSum, rightAns.maxSum);
            node.maxNode = INT_MAX;
            node.minNode = INT_MIN; 
        }
        ans = std::max(ans, node.maxSum);
        return node;
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        f(root);
        return ans;
    }
};