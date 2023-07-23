// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
class Solution {
private:
    vector<vector<int>> dp;
    map<pair<int, int>, int> maxi;

    int f(int i, int j) {
        // base case
        if(i == j) return 0; // single node or leaf node
        if(dp[i][j] != -1) return dp[i][j];

        // recursive case
        int mini = INT_MAX;
        for(int money=i; money<j; money++) {
            int legAns = f(i, money);
            int offAns = f(money+1, j);

            // work case
            int curAns = maxi[{i, money}] * maxi[{money+1, j}];
            int totAns = curAns + legAns + offAns;
            mini = std::min(mini, totAns);
        }

        // return case
        dp[i][j] = mini;
        return mini;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        maxi.clear();
        for(int i=0; i<arr.size(); i++) {
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++) maxi[{i, j}] = std::max(arr[j], maxi[{i, j-1}]);
        }
        dp.resize(arr.size()+1, vector(arr.size()+1, -1));
        return f(0, arr.size()-1);
    }
};