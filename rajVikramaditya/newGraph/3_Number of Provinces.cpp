// https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
#define UG std::unordered_map<int, std::set<int>>
#define VIS std::unordered_map<int, bool>
class Solution {
public:
    void dfs(int root, UG& adj, VIS& vis) {
        vis[root] = true;
        for(auto &child : adj[root]) if(!vis[child]) dfs(child, adj, vis); 
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        // prepare adjList
        UG adjList;
        for(int i=0; i<adj.size(); i++) {
            int u = i+1;
            for(int j=0; j<adj[i].size(); j++) {
                if(adj[i][j] == 1) {
                    int v = j+1;
                    adjList[u].insert(v);
                    adjList[v].insert(u);
                }
            }
        }
        VIS vis;
        int CC = 0;
        for(int i=1; i<=V; i++) {
            if(!vis[i]) {
                CC++;
                dfs(i, adjList, vis);
            }
        }
        return CC;
    }
};