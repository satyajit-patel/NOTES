// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
class Solution {
public:
    int f(vector<int>& arr, map<pair<int, int>, int>& mp, int left, int right, vector<vector<int>>& dp) {
        // base case
        if(left == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        // recursive case
        int mini = INT_MAX;
        for(int i=left; i<right; i++) {
            int curAns = mp[{left, i}] * mp[{i+1, right}];
            int leftAns = f(arr, mp, left, i, dp);
            int rightAns = f(arr, mp, i+1, right, dp);
            int totalAns = curAns + leftAns + rightAns;
            mini = std::min(mini, totalAns);
        }

        // return case
        dp[left][right] = mini;
        return mini;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int N = arr.size();
        std::map<std::pair<int, int>, int> maxEleInRange;
        for(int i=0; i<N; i++) {
            maxEleInRange[{i, i}] = arr[i];
            for(int j=i+1; j<N; j++) maxEleInRange[{i, j}] = std::max(arr[j], maxEleInRange[{i, j-1}]);
        }
        std::vector<std::vector<int>> dp(N+1, std::vector(N+1, -1));
        return f(arr, maxEleInRange, 0, N-1, dp);
    }
};