// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
class Solution {
private:
    vector<vector<int>> dp;
    int f(int i, int j) {
        // base case
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        // recursive case
        int mini = INT_MAX;
        for(int money=i; money<=j; money++) {
            int leftAns = f(i, money-1) + money;
            int rightAns = f(money+1, j) + money;

            // work case
            int maxi = std::max(leftAns, rightAns);
            mini = std::min(mini, maxi); // maximum penalty is minimum money required
        }

        // return case
        dp[i][j] = mini;
        return mini;
    }
public:
    int getMoneyAmount(int n) {
        dp.resize(n+1, vector<int>(n+1, -1));
        return f(1, n);
    }
};