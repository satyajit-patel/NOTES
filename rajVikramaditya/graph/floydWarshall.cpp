#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vpi vector<pair<int>>
#define vpi vector<pair<int, int>>

vi floydWarshall(int n, vpi adj[]) {
    vii dist(n+1, vi(n+1, INT_MAX));
    //O(M)
    for (int i = 1; i<=n; i++) {
        dist[i][i]=0;//all diagonal will be zero

        //iterate the edge of that node
        for(auto &it : v[i]){//O(1) beoz its for only 2 edge
            //if multiple edge are going from same node, then select the one with minimum weight
            dist[i][it.first]=min(dist[i][it.first], it.second);
        }
    }
    //O(N^3)
    for (int k=1; k<=n; k++) {//k is no of phases
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if(dist[i][k] != INF and dist[k][j] != INF)
                    dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}
int main() {
    int n,m; cin>>n>>m;
    vpi adj[n+1];
    while(m--) {
        int i,j,w; cin>>i>>j>>w;
        v[i].push_back({j,w});
        //v[j].push_back({i,w});
    }

    auto dist=floyd_warshall(n, adj);
    for(auto &row : dist) {
	for(auto &it : row) cout<<it<<" ";
	cout<<endl;
    }
    return 0;
}