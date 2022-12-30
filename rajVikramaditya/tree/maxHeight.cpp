#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>

vi arr[2 * 100005];
int height = 0;
void dfs(int root, int parent = -1, int level = 0) {
    cout<<root<<" ";
    height = max(height, level);
    for(auto &it:arr[root]) {
        if(it != parent) dfs(it, root, level+1);
    }
}
int main() {
	int n; cin>>n;
	for(int i=0; i<n-1; i++) {
		int u,v; cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	dfs(1);
    	cout<<height;
	return 0;
}