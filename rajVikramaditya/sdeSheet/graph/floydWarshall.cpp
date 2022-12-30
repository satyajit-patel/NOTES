//link --> https://bit.ly/3Kb41Ny
#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<pair<int, int>> adj[n+1];
    for(auto &row : edges) {
        int u = row[0];
        int v = row[1];
        int w = row[2];
        //given directed graph
        adj[u].push_back({v, w});
    }
    int inf = 1000000000;
    vii dist(n+1, vi(n+1, inf));
    for(int i=1; i<=n; i++) {
        dist[i][i] = 0;
        for(auto &it : adj[i]) {
            int u = i;
            int v = it.first;
            int wt = it.second;
            dist[u][v] = min(dist[u][v], wt);
        }
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dist[i][k] != inf && dist[k][j] != inf)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist[src][dest];
}