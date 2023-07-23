// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
private:
    std::vector<std::vector<int>> dp;
    int f(int n, int w, int* wt, int* val) {
        // base case
        if(n < 0) return 0;
        if(w <= 0) return 0;
        if(dp[n][w] != -1) return dp[n][w];
        
        // recursive case
        int incl = 0;
        if(wt[n] <= w) incl = val[n] + f(n-1, w-wt[n], wt, val);
        int excl = 0 + f(n-1, w, wt, val);
        
        // work case
        int ans = std::max(incl, excl);
        
        // return case
        dp[n][w] = ans;
        return ans;
    }
public:
    int knapSack(int W, int wt[], int val[], int n) { 
       wt = wt, val = val;
       dp.resize(n+1, std::vector<int>(W+1, -1));
       return f(n-1, W, wt, val);
    }
};