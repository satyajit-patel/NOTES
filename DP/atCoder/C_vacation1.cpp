
// https://atcoder.jp/contests/dp/tasks/dp_c
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>

vi A;
vi B;
vi C;
int dp[1000005][4];
int n;
int vacation(int idx, int prev) {
	if(idx == n) return 0;
	if(dp[idx][prev] != -1) return dp[idx][prev];
	
	int maxi = INT_MIN;
	if(prev == 0) {
		int firstTask  = A[idx] + vacation(idx+1, 1);
		int secondTask = B[idx] + vacation(idx+1, 2);
		int thirdTask  = C[idx] + vacation(idx+1, 3);
		maxi = max(firstTask, max(secondTask, thirdTask));
	}
	else if(prev == 1) {
		int secondTask = B[idx] + vacation(idx+1, 2);
		int thirdTask  = C[idx] + vacation(idx+1, 3);
		maxi = max(secondTask, thirdTask);
	}
	else if(prev == 2) {
		int firstTask  = A[idx] + vacation(idx+1, 1);
		int thirdTask  = C[idx] + vacation(idx+1, 3);
		maxi = max(firstTask, thirdTask);
	}
	else {
		int firstTask  = A[idx] + vacation(idx+1, 1);
		int secondTask = B[idx] + vacation(idx+1, 2);
		maxi = max(firstTask, secondTask);
	}
	return dp[idx][prev] = maxi;
}
int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		int x,y,z; cin>>x>>y>>z;
		A.push_back(x);
		B.push_back(y);
		C.push_back(z);	
	}
	memset(dp, -1, sizeof(dp));
	cout<<vacation(0, 0)<<endl;
	return 0;
}