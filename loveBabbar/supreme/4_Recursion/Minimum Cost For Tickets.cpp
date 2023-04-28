// https://leetcode.com/problems/minimum-cost-for-tickets/description/
class Solution {
public:
    int f(vector<int>& days, vector<int>& costs, vector<int>& dp, int i=0) {
        // base case
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];

        // recursive case
        int day1 = costs[0] + f(days, costs, dp, i+1);

        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j<days.size() && days[j]<=passEndDay) j++;
        int day7 = costs[1] + f(days, costs, dp, j);

        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j<days.size() && days[j]<=passEndDay) j++;
        int day30 = costs[2] + f(days, costs, dp, j);

        int ans = std::min(day1, std::min(day7, day30));

        // store and return
        dp[i] = ans;
        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        std::vector<int> dp(days.size()+1, -1);
        return f(days, costs, dp);
    }
};