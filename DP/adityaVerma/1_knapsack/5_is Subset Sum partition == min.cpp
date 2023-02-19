// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    bool f(int n, int* arr, int sum, vector<vector<int>>& dp, int i=0) {
        // base case 
        if(i >= n) return sum == 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        // choice
        int include = 0, exclude = 0;
        if(arr[i] <= sum) include = f(n, arr, sum-arr[i], dp, i+1);
        exclude = f(n, arr, sum, dp, i+1);
        
        int optimal = include || exclude;
        dp[i][sum]  = optimal;
        return optimal;
    }
	int minDifference(int arr[], int n)  {
	    // s1 - s2 = min
	    int totSum = 0;
	    for(int i=0; i<n; i++) totSum += arr[i];
	    vector<vector<int>> dp(n+1, vector<int>(totSum+1, -1));
	    vector<int> partition1, partition2;
	    for(int sum=0; sum<=totSum; sum++) {
	        if(f(n, arr, sum, dp)) {
	            partition1.push_back(sum);
	            partition2.push_back(totSum-sum);
	        }
	    }
	    int minDiff = 1e9;
	    for(int i=0; i<partition1.size(); i++) {
	        int curDiff = std::abs(partition1[i] - partition2[i]);
	        minDiff  = std::min(minDiff, curDiff);
	    }
	    return minDiff;
	} 
};