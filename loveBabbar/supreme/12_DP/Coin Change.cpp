// https://leetcode.com/problems/coin-change/description/
class Solution {
private:
    std::vector<int> dp, coins;
    int f(int sum) {
        // base case
        if(sum < 0) return INT_MAX;
        if(sum == 0) return 0;
        if(dp[sum] != -1) return dp[sum];

        // recursive case
        int mini = INT_MAX;
        for(auto &it : this->coins) {
            int ans = f(sum-it);
            if(ans != INT_MAX) mini = std::min(mini, 1+ans);
        }

        // return case
        dp[sum] = mini;
        return mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        dp.resize(amount+1, -1);
        int mini = f(amount);
        if(mini >= INT_MAX) return -1;
        return mini;
    }
};