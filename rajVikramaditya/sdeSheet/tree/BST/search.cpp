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
    TreeNode* searchBST(TreeNode* root, int val) {
        //tc = O(logN) as we are traversing the entire node
        //we wre just traversing the required path i.e in worst we go till height of tre
        while(root != NULL and root->val != val){
            (root->val > val) ? root = root->left : root = root->right;
        }
        return root;
    }
};