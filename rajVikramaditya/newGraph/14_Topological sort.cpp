// https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
class Solution {
public:
    void dfs(int root, vector<int> adj[], vector<int>& vis, stack<int>& stack) {
        vis[root] = 1;
        for(auto &child : adj[root]) {
            if(!vis[child]) dfs(child, adj, vis, stack);
        }
        stack.push(root);
    }

	vector<int> topoSort(int V, vector<int> adj[]) {
	    std::vector<int> vis(V, 0);
	    std::stack<int> stack;
	    for(int i=0; i<V; i++) {
	        if(!vis[i]) dfs(i, adj, vis, stack);
	    }
	    
	    std::vector<int> toposort;
	    while(!stack.empty()) {
	        int node = stack.top();
	        stack.pop();
	        toposort.push_back(node);
	    }
	    return toposort;
	}
};