// https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
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
};