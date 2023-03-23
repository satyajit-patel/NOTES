// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
class Solution {
public:
    bool dfs(int root, vector<int> adj[], vector<int>& vis) {
        vis[root] = 2;
        for(auto &child : adj[root]) {
            if(!vis[child]) {
                if(dfs(child, adj, vis)) return true;
            }
            else if(vis[child] == 2) return true;
        }
        vis[root] = 1;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        std::vector<int> vis(V, 0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis)) return true;
            }
        }
        return false;
    }
};