//https://leetcode.com/problems/combination-sum-ii/submissions/
#define vi vector<int>
#define vvi vector<vector<int>>
class Solution {
public:
    void sub(int i, vi &arr, int sum, vi &ds, vvi &ans) {
            if(sum == 0) {
                ans.push_back(ds);
                return;
            }
        //logic of must not contain duplicate
        for(int ind=i; ind<arr.size(); ind++) {
            if(arr[ind] <= sum) {
                if(ind != i && arr[ind] == arr[ind-1]) continue;
                ds.push_back(arr[ind]);
                sum -= arr[ind];
                sub(ind+1, arr, sum, ds, ans);
                ds.pop_back();
                sum += arr[ind];
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vvi ans; vi ds;
        sort(arr.begin(), arr.end());
        sub(0, arr, target, ds, ans);
        return ans;
    }
};