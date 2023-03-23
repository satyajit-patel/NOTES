// https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule
class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
	    std::vector<int> inDegre(V, 0);
	    for(int i=0; i<V; i++) {
	        for(auto &child : adj[i]) inDegre[child]++;
	    }
	    
	    std::queue<int> queue;
	    for(int i=0; i<V; i++) if(inDegre[i] == 0) queue.push(i);
	    
	    std::vector<int> toposort;
        while(!queue.empty()) {
            int root = queue.front();
            queue.pop();
            toposort.push_back(root);
            for(auto &child : adj[root]) {
                inDegre[child]--;
                if(inDegre[child] == 0) queue.push(child);
            }
        }
	    return toposort;
	}

    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        std::vector<int> adj[n];
        for(auto &row : prerequisites) {
            // just store the reverse order
            int u = row[1];
            int v = row[0];
            adj[u].push_back(v);
        }
        
        std::vector<int> toposort = topoSort(n, adj);
        if(toposort.size() == n) return toposort;
        return {};
    }
};