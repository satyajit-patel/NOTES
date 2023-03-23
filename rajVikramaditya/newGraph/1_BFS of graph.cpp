// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
#define UG std::unordered_map<int, std::set<int>>
#define VIS std::unordered_map<int, bool>
class Solution {
public:
    std::vector<int> bfs(int root, UG& adjList) {
        VIS vis;
        vis[root] = true;
        std::queue<int> q;
        q.push(root);
        
        std::vector<int> bfs;
        while(!q.empty()) {
            root = q.front();
            q.pop();
            bfs.push_back(root);
            for(auto &child : adjList[root]) {
                if(!vis[child]) {
                    vis[child] = true;
                    q.push(child);
                }
            }
        }
        return bfs;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // prepare adjList
        UG adjList;
        for(int i=0; i<V; i++) {
            int u = i;
            for(auto &it : adj[i]) {
                int v = it;
                adjList[u].insert(v);
            }
        }
        return bfs(0, adjList);
    }
};