// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{   
public:
    bool f(vector<int>& arr, int sum, vector<vector<int>>& dp, int i=0) {
        // base case 
        if(i >= arr.size()) return sum == 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        // choice
        int include = 0, exclude = 0;
        if(arr[i] <= sum) include = f(arr, sum-arr[i], dp, i+1);
        exclude = f(arr, sum, dp, i+1);
        
        int optimal = include || exclude;
        dp[i][sum]  = optimal;
        return optimal;
    }
    bool isSubsetSum(vector<int>& arr, int sum){
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
        return f(arr, sum, dp);
    }
};