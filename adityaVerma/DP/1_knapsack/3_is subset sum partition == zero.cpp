// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
class Solution{
public:
    bool f(int N, int* arr, int sum, vector<vector<int>>& dp, int i=0) {
        // base case
        if(i >= N) return sum == 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        // choice
        int include = 0, exclude = 0;
        include = f(N, arr, sum-arr[i], dp, i+1);
        exclude = f(N, arr, sum, dp, i+1);
        
        int optimal = include || exclude;
        dp[i][sum]  = optimal;
        return optimal;
    }
    int equalPartition(int N, int arr[]) {
	/*
		s1 - s2 = 0
		totSum - s2 - s2 = 0
		totSum - (2 * s2) = 0
		totSum = 2 * s2
		s2 = totSum/2
		i.e sum = totSum/2
 	*/
        int totSum = 0;
        for(int i=0; i<N; i++) totSum += arr[i];
        if(totSum%2) return 0;
        int sum = totSum/2;
        vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
        return f(N, arr, sum, dp);
    }
};