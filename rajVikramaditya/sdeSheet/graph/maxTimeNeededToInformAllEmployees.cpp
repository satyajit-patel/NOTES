//https://leetcode.com/problems/time-needed-to-inform-all-employees/
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int root = headID;
        vector<int> vis(n, 0);
        vis[root] = 1;
        int ans = INT_MIN;
        vector<int> adj[n];
        for(int i=0; i<n; i++) {
            if(manager[i] == -1) continue;
            adj[i].push_back(manager[i]);
            adj[manager[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({root, informTime[root]});
        while(!q.empty()) {
            int root = q.front().first;
            int time = q.front().second;
            q.pop();
            ans = max(time, ans);
            for(auto &it : adj[root]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({it, time+informTime[it]});
                }
            }
        }
        return ans;
    }
};