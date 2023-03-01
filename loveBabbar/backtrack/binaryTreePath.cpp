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
// https://leetcode.com/problems/binary-tree-paths/
class Solution {
public:
    void f(TreeNode* root, vector<string>& ans, string s) {
        //baseCase
        if(!root) return;
        if(!root->left && !root->right) {
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        
        //recursiveCase
        string temp = s;
        s += to_string(root->val);
        s += "->";
        f(root->left, ans, s);
        f(root->right, ans, s);
        // //backtrack no need as we are passing the string by value
        // s = temp;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        f(root, ans, s);
        return ans;
    }
};

				// |
				// |
				// |
				// |
class Solution {
public:
    void f(TreeNode* root, vector<string>& ans, string& s) {
        //baseCase
        if(!root) return;
        if(!root->left && !root->right) {
            string temp = s;
            s += to_string(root->val);
            ans.push_back(s);
            //backtrack
            s  = temp;
            return;
        }
        
        //recursiveCase
        string temp = s;
        s += to_string(root->val);
        s += "->";
        f(root->left, ans, s);
        f(root->right, ans, s);
        //backtrack if we pass the string as reference
        s = temp;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        f(root, ans, s);
        return ans;
    }
};