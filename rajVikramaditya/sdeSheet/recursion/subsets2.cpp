//https://leetcode.com/problems/subsets-ii/
#define vi vector<int>
#define vvi vector<vector<int>>
class Solution {
public:
    void sub(int i, int n, vi &nums, vi &ds, vvi &ans) {
        ans.push_back(ds);
        for(int ind=i; ind<n; ind++) {
            if(ind != i && nums[ind] == nums[ind-1]) continue;
            ds.push_back(nums[ind]);
            sub(ind+1, n, nums, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vvi ans; vi ds;
        sort(nums.begin(), nums.end());
        sub(0, nums.size(), nums, ds, ans);
        return ans;
    }
};