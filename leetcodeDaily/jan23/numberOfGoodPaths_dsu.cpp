// https://leetcode.com/problems/number-of-good-paths/description/
class Solution {
public:
    // dsu
    vector<int> parent;
    int findParent(int x) {
        return parent[x] == -1 ? x : parent[x] = findParent(parent[x]);
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        // each node is a good path
        int ans = n;
        parent.resize(n, -1);
        vector<int> subtree(n, 1);
        // sort by vals
        std::sort(edges.begin(), edges.end(), [&](vector<int>& v1, vector<int>& v2) {
           return std::max(vals[v1[0]], vals[v1[1]]) < std::max(vals[v2[0]], vals[v2[1]]);
        });
        // iterate each edge
        for (auto &row : edges) {
            int x = row[0];
            int y = row[1];
            x = findParent(x);
            y = findParent(y);
            if (vals[y] < vals[x]) parent[y] = x;
            else if(vals[x] < vals[y]) parent[x] = y;
            else {
                parent[x] = y;
                ans += subtree[x] * subtree[y];
                subtree[y] += subtree[x];
            } 
        }
        return ans;
    }
};