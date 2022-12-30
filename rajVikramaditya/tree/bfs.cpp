#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>

vi arr[2 * 100005];
void bfs(int root) {
	queue<pair<int, int>> q;
    q.push({root, -1});
    while(!q.empty()) {
        int rootNode = q.front().first;
        int parent = q.front().second;
        cout<<rootNode<<" ";
        q.pop();
        for(auto &it:arr[rootNode]) {
            if(it != parent) q.push({it, rootNode});
        }
    }
}
int main() {
	int n; cin>>n;
	for(int i=0; i<n-1; i++) {
		int u,v; cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	bfs(1);
	return 0;
}