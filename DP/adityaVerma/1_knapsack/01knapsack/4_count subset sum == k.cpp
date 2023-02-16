// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
class Solution{
public:
    int MOD = 1e9 + 7;
    int f(int n, int* arr, int sum, vector<vector<int>>& dp, int i=0) {
        // base case
        if(i >= n) return sum == 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        // choice
        int include = 0, exclude = 0;
        if(arr[i] <= sum) include = f(n, arr, sum-arr[i], dp, i+1);
        exclude = f(n, arr, sum, dp, i+1);
        
        int optimal = (include + exclude) % MOD;
        dp[i][sum]  = optimal;
        return optimal;
    } 
	int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return f(n, arr, sum, dp);
	}
	  
};