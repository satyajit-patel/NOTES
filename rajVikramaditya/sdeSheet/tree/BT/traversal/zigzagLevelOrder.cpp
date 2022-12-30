/**
 * Definition for a binary tree node.
 * struct TreeNode {
       https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vvi ans;
        vi level;
        if(!root) return ans;
        
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                root = q.front();
                q.pop();
                level.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            if(leftToRight) {
                ans.push_back(level);
                level.clear();
                leftToRight = !leftToRight;
            }
            else {
                reverse(level.begin(), level.end());
                ans.push_back(level);
                level.clear();
                leftToRight = !leftToRight;
            }
        }
        return ans;
    }
};











vector <int> zigZagTraversal(Node* root) {
    	vector<int> ans;
    	if(!root) return ans;
    	bool leftTurn = true;
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()) {
    	    int n = q.size();
    	    vector<int> tmp;
    	    for(int i=0; i<n; i++) {
    	        root = q.front();
    	        q.pop();
    	        tmp.push_back(root->data);
    	        if(root->left) q.push(root->left);
    	        if(root->right) q.push(root->right);
    	    }
    	    if(leftTurn) {
    	        for(auto &it : tmp) ans.push_back(it);
    	        leftTurn = !leftTurn;
    	    }
    	    else {
    	        reverse(tmp.begin(), tmp.end());
    	        for(auto &it : tmp) ans.push_back(it);
    	        leftTurn = !leftTurn;
    	    }
    	}
    	return ans;
    }