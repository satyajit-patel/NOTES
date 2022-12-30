#include<bits/stdc++.h>

using namespace std;
vector<int> di = {0,1,0,-1};
vector<int> dj = {1,0,-1,0};
string dir = "RDLU";
void go(int i, int j, string s, vector<vector<int>> &arr, vector<vector<int>> &vis) {
	int n = arr.size();
	int m = arr[0].size();
	if(j>=m || i>=n || j<0 || i<0 || arr[i][j]==1 || vis[i][j]==1) return;
	if(i==n-1 && j==m-1) {
		cout<<s<<"\n";
		return;
	}

	for(int x=0; x<4; x++) {
		vis[i][j]=1;
		go(i+di[x], j+dj[x], s+dir[x], arr, vis);
		vis[i][j]=0;
	}
}
int main() {
	int n=4, m=4;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> vis(n, vector<int>(m, 0));
	arr[1][2]=1;
	arr[2][1]=1;
	arr[2][2]=1;
	string s;
	go(0,0,s,arr,vis);			   
	return 0;
}