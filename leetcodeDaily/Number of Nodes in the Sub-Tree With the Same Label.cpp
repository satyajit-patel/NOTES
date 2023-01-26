// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
#define ADJ std::unordered_map<int, std::set<int>>
#define VIS std::unordered_map<int, bool>
class Solution {
public:
    vector<int> dfs(ADJ& adj, VIS& vis, string& labels, vector<int>& ans, int root = 0) {
        vis[root] = true;
        vector<int> count(26, 0);
        for(auto &child : adj[root]) {
            if(!vis[child]) {
                vector<int> temp = dfs(adj, vis, labels, ans, child);
                for(int i=0; i<26; i++) count[i] += temp[i];
            }
        }
        char ch = labels[root];
        count[ch - 'a']++;
        ans[root] = count[ch - 'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // prepare adj list
        ADJ adj;
        VIS vis;
        for(auto &row : edges) {
            int u = row[0];
            int v = row[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        vector<int> ans(n, 0);
        dfs(adj, vis, labels, ans);
        return ans;
    }
};