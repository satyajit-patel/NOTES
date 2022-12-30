/**
 * Definition for a binary tree node.
 * struct TreeNode {
       https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        if(!root) return ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> m;
        while(!q.empty()) {
            root = q.front().first;
            int vertex = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            m[vertex][level].insert(root->val);
            if(root->left) q.push({root->left, {vertex-1, level+1}});
            if(root->right) q.push({root->right, {vertex+1, level+1}});
        }
        for(auto &it : m) {
            for(auto &x : it.second) {
                for(auto z=x.second.begin(); z != x.second.end(); z++) {
                    tmp.push_back(*z);
                }
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};