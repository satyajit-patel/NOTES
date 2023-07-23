// https://leetcode.com/problems/course-schedule-ii/
#define VIS std::unordered_map<int, int>
#define ADJ std::unordered_map<int, std::unordered_set<int>>
class Solution {
private:
    std::vector<int> getToposortUsingBfs(VIS& vis, ADJ& adj, int n) {
        std::vector<int> ans, inDegree(n, 0);
        for(int root=0; root<n; root++) {
            for(auto &child : adj[root]) inDegree[child]++;
        }
        std::queue<int> q;
        for(int root=0; root<n; root++) {
            if(inDegree[root] == 0) q.push(root);
        }
        while(!q.empty()) {
            int root = q.front();
            q.pop();
            ans.push_back(root);
            for(auto &child : adj[root]) {
                inDegree[child]--;
                if(inDegree[child] == 0) q.push(child);
            }
        }
        return ans;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ADJ adj;
        VIS vis;
        for(auto &row : prerequisites) {
            int u = row[0];
            int v = row[1];
            adj[v].insert(u);
        }
        std::vector<int> ans = getToposortUsingBfs(vis, adj, numCourses);
        if(ans.size() == numCourses) return ans;
        return {};
    }
};