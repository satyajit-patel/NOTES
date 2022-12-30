//equal subset sum

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define endl "\n"
#define vii vector<vector<int>> 

bool f(vi &nums, int i, int n, int sum, vii &dp) {
	if(i == n) return sum == 0;
	if(dp[i][sum] != -1) return dp[i][sum];
	
	bool pick = false;
	if(nums[i] <= sum) pick = f(nums, i+1, n, sum-nums[i], dp);
	return dp[i][sum] = (pick ||  f(nums, i+1, n, sum, dp));
}
bool canPartition(vector<int>& nums, int n) {
	int sum = 0;
	for(auto &it:nums) sum += it;
	if(sum%2 != 0) return false;
	vii dp(n+1, vi(sum+1, -1));
	if(f(nums, 0, nums.size(), sum/2, dp) == true) return true;
	return false;
}
int main() {
	int n; cin>>n;
	vi arr(n);
	for(auto &it:arr) cin>>it;
	cout<<canPartition(arr, n)<<endl;
	return 0;
}