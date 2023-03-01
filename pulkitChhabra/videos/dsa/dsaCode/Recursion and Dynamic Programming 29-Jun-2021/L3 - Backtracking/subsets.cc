// https://leetcode.com/problems/subsets/

class Solution {
	void subsets_util(vector<int> &nums, int i, vector<int> &cur, vector<vector<int> > &ans)
	{
		if (i == nums.size())
		{
			ans.push_back(cur);
			return;
		}

		subsets_util(nums, i + 1, cur, ans);

		cur.push_back(nums[i]);
		subsets_util(nums, i + 1, cur, ans);
		cur.pop_back();
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int> > ans;
		vector<int> cur;
		subsets_util(nums, 0, cur, ans);
		return ans;
	}
};