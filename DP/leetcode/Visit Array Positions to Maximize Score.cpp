// https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/
class Solution {
public:
    vector<int> A;
    int penalty;
    long long dp[100000+5][2+5];

    long long f(int i, int parityBit) {
        // base case
        if(i >= A.size()) return 0;
        if(dp[i][parityBit] != -1) return dp[i][parityBit];

        // recursive case
        long long head = 0;
        if((A[i]&1) == parityBit) head = A[i] + f(i+1, parityBit);
        else head = A[i] - penalty + f(i+1, !parityBit);
        long long tail = f(i+1, parityBit);

        // return case
        long long ans = std::max(head, tail);
        dp[i][parityBit] = ans;
        return ans;
    }

    long long maxScore(vector<int>& nums, int x) {
        A.clear();
        A = nums;
        penalty = x;
        int parityBit = 0;
        if(nums[0]&1) parityBit = 1;
        std::memset(dp, -1, sizeof dp);
        long long ans = nums[0] + f(1, parityBit);
        return ans;
    }
};