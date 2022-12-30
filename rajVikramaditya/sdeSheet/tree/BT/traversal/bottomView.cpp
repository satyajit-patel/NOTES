class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(!root) return ans;
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            root = q.front().first;
            int vertex = q.front().second;
            q.pop();
            m[vertex] = root->data;
            if(root->left) q.push({root->left, vertex-1});
            if(root->right) q.push({root->right, vertex+1});
        }
        for(auto &it : m) ans.push_back(it.second);
        return ans;
    }
};