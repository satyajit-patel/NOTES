// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
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

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        std::vector<int> adjRev[V];
        for(int i=0; i<V; i++) {
            int root = i;
            for(auto &child : adj[root]) adjRev[child].push_back(root);
        }
        std::vector<int> toposort = topoSort(V, adjRev);
        std::sort(toposort.begin(), toposort.end());
        return toposort;
    }
};