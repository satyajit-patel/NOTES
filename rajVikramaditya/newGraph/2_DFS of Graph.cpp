// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
#define UG std::unordered_map<int, std::set<int>>
#define VIS std::unordered_map<int, bool>
class Solution {
public:
    void dfs(int root, vector<int> adj[], VIS& vis, std::vector<int>& ans) {
        vis[root] = true;
        ans.push_back(root);
        for(auto &child : adj[root]) if(!vis[child]) dfs(child, adj, vis, ans); 
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // not preparing adjList because question is asked to print from left child to right, not in sorted form
        // // prepare adjList
        // UG adjList;
        // for(int i=0; i<V; i++) {
        //     int u = i;
        //     for(auto &it : adj[i]) {
        //         int v = it;
        //         adjList[u].insert(v);
        //     }
        // }
        
        VIS vis;
        std::vector<int> ans;
        dfs(0, adj, vis, ans);
        return ans;
    }
};