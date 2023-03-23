// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
class Solution {
public:
    bool bfs(int root, vector<int> adj[], vector<int>& vis) {
        vis[root] = 1;
        std::queue<std::pair<int, int>> q;
        q.push({root, -1});
        
        while(!q.empty()) {
            root = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto &child : adj[root]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    q.push({child, root});
                }
                else if(child != parent) return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++) if(!vis[i]) if(bfs(i, adj, vis)) return true;
        return false;
    }
};