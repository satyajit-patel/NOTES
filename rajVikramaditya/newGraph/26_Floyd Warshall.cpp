// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall
class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
	    int N = matrix.size();
	    for(int i=0; i<N; i++) {
	        matrix[i][i] = 0;
	        for(int j=0; j<N; j++) if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	    }
	    
	    for(int via=0; via<N; via++) {
	        for(int i=0; i<N; i++) {
	            for(int j=0; j<N; j++) matrix[i][j] = std::min(matrix[i][j], matrix[i][via]+matrix[via][j]);
	        }
	    }
	    
	   // for(int i=0; i<N; i++) if(matrix[i][i] < 0) // Negative cycle exist
	    for(int i=0; i<N; i++) {
	        for(int j=0; j<N; j++) if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	    }
	}
};