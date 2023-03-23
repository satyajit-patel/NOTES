// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU
class Solution {
public:
    vector<int> bellman_ford(int N, vector<vector<int>>& edges, int S) {
	    std::vector<std::vector<int>> dist(N, std::vector<int>(N, 1e8));
	    for(int i=0; i<N; i++) dist[i][i] = 0;
	    for(auto &row : edges) {
	        int u = row[0];
	        int v = row[1];
	        int w = row[2];
	        dist[u][v] = std::min(dist[u][v], w);
	    }
	    
	    for(int via=0; via<N; via++) {
	        for(int i=0; i<N; i++) {
	            for(int j=0; j<N; j++) dist[i][j] = std::min(dist[i][j], dist[i][via]+dist[via][j]);
	        }
	    }
	    
	    for(int i=0; i<N; i++) if(dist[i][i] < 0) return {-1};
	    return dist[S];
    }
};