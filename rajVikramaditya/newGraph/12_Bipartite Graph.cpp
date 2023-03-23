// https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
class Solution {
public:
    bool bfs(int root, vector<int>adj[], vector<int>& color) {
	    color[root] = 1;
	    std::queue<int> q;
	    q.push(root);
	    
	    while(!q.empty()) {
	        root = q.front();
	        q.pop();
	        for(auto &child : adj[root]) {
	            if(color[child] == -1) {
	                color[child] = !color[root];
	                q.push(child);
	            }
	            else if(color[child] == color[root]) return false;
	        }
	    }
	    return true;
    }

	bool isBipartite(int V, vector<int>adj[]) {
	    // if we can color a graph using only 2 color such that no adjacent node have same color then it's called as bipartite
	    std::vector<int> color(V, -1);
	    for(int i=0; i<V; i++) {
	        if(color[i] == -1) {
	            if(!bfs(i, adj, color)) return false;
	        }
	    }
	    return true;
	}
};