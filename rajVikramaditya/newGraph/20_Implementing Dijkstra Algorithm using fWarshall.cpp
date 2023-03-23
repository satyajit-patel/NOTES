// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
class Solution {
public:
    // will give TLE 
    // dijkstra : O(ELogV)
    // fWarshall : O(N^3)
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        std::vector<std::vector<int>> dist(V, std::vector<int>(V, 1e8));
        for(int i=0; i<V; i++) dist[i][i] = 0;
        for(int i=0; i<V; i++) {
            int root = i;
            int u = root;
            for(auto &child : adj[root]) {
                int v = child[0];
                int w = child[1];
                dist[u][v] = std::min(dist[u][v], w);
                dist[v][u] = std::min(dist[v][u], w);
            }
        }
        
        for(int via=0; via<V; via++) {
	        for(int i=0; i<V; i++) {
	            for(int j=0; j<V; j++) dist[i][j] = std::min(dist[i][j], dist[i][via]+dist[via][j]);
	        }
	    }
	    
	   // for(int i=0; i<N; i++) if(dist[i][i] < 0) return {-1};
	    return dist[S];
    }
};