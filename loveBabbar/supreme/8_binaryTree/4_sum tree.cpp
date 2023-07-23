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
 
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
class Solution {
public:
    int convertToSumTree(TreeNode* root) {
        // base case
        if(!root) return 0;

        // recursive case
        int leftSum = convertToSumTree(root->left);
        int rightSum = convertToSumTree(root->right);

        // store and return
        int totalSum = root->val + leftSum + rightSum;
        root->val = totalSum;
        return totalSum;
    }

    void getLevelOrder(TreeNode* root, std::vector<std::vector<int>>& levelOrder) {
        if(!root) return;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int N = q.size();
            std::vector<int> temp;
            for(int i=0; i<N; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelOrder.push_back(temp);
        }
    }

    void getPostOrder(TreeNode* root, std::vector<int>& postOrder) {
        // base case
        if(!root) return;

        // recursive case
        getPostOrder(root->left, postOrder);
        getPostOrder(root->right, postOrder);
        postOrder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> postOrder;
        getPostOrder(root, postOrder);

        std::vector<std::vector<int>> levelOrder;
        getLevelOrder(root, levelOrder);
        for(auto &row : levelOrder) {
            for(auto &it : row) cout<<it<<" ";
            cout<<std::endl;
        }

        convertToSumTree(root);
        std::cout<<std::endl<<std::endl;
        levelOrder.clear();

        getLevelOrder(root, levelOrder);
        for(auto &row : levelOrder) {
            for(auto &it : row) cout<<it<<" ";
            cout<<std::endl;
        }

        return postOrder;
    }
};