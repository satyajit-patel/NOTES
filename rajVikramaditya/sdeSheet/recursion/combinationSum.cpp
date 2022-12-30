//https://leetcode.com/problems/combination-sum/
#define vi vector<int>
#define vvi vector<vector<int>>
class Solution {
public:
    void sub(int i, int n, vi &arr, int sum, vi &ds, vvi &ans) {
        if(i == n) {
            if(sum == 0) ans.push_back(ds);
            return;
        }
        if(arr[i] <= sum) {
            ds.push_back(arr[i]);
            sum -= arr[i];
            sub(i, n, arr, sum, ds, ans);
            ds.pop_back();
            sum += arr[i];
        }
        sub(i+1, n, arr, sum, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vvi ans; vi ds;
        sub(0, candidates.size(), candidates, target, ds, ans);
        return ans;
    }
};