// https://leetcode.com/problems/predict-the-winner/description/
class Solution {
public:
    vector<int> A;
    int dp[20+1][20+1];

    int f(int i, int j) {
        // base case
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        // recursive case
        int head = A[i] - f(i+1, j);
        int tail = A[j] - f(i, j-1);

        // return case
        int ans = std::max(head, tail);
        dp[i][j] = ans;
        return ans;
    }

    bool PredictTheWinner(vector<int>& nums) {
        A.clear(), A = nums;

        std::memset(dp, -1, sizeof dp);
        int ans = f(0, A.size()-1);
        return ans >= 0;
    }
};