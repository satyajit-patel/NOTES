// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
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

    bool isCyclic(int V, vector<int> adj[]) {
        std::vector<int> toposort = topoSort(V, adj);
        if(toposort.size() == V) return false;
        return true;
    }

	bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
	    std::vector<int> adj[N];
	    for(auto &it : prerequisites) {
	        int u = it.first;
	        int v = it.second;
	        adj[u].push_back(v);
	    }
	    if(isCyclic(N, adj)) return false;
	    return true;
	}
};