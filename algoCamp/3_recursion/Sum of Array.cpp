// https://practice.geeksforgeeks.org/problems/sum-of-array2326/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    int f(int i, int N, int* arr, vector<int>& dp) {
        // base case
        if(i >= N) return 0;
        if(dp[i] != -1) return 0;
        
        // recursive case
        int sum = 0;
        sum += arr[i] + f(i+1, N, arr, dp);
        
        // return case
        dp[i] = sum;
        sum;
    }

	int sum(int arr[], int n) {
	    std::vector<int> dp(n+1, -1);
	    return f(0, n, arr, dp);
	}
};