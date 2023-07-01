// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		vector<vector<int> > dp(n, vector<int>(4));
		vector<int> ans[n][4];

		int sumk = 0;

		for (int i = 0; i < n; ++i)
		{
			sumk += nums[i];
			if (i >= k)
				sumk -= nums[i - k];
			for (int j = 1; j <= 3; ++j)
			{
				if (i >= k)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - k][j - 1] + sumk);

					if (dp[i][j] == dp[i - 1][j])
						ans[i][j] = ans[i - 1][j];

					else
						ans[i][j] = ans[i - k][j - 1], ans[i][j].push_back(i - k + 1);
				}

				else if (i == k - 1 and j == 1)
				{
					dp[i][j] = sumk;
					ans[i][j] = {i - k + 1};
				}
			}
		}
		return ans[n - 1][3];
	}
};