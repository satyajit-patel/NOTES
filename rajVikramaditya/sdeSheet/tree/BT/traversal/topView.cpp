/*
https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
    public:
    vector<int> topView(Node *root) {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            root = q.front().first;
            int vertex = q.front().second;
            q.pop();
            if(m.find(vertex) == m.end()) m[vertex] = root->data;
            if(root->left) q.push({root->left, vertex-1});
            if(root->right) q.push({root->right, vertex+1});
        }
        for(auto &it : m) ans.push_back(it.second);
        return ans;
    }

};