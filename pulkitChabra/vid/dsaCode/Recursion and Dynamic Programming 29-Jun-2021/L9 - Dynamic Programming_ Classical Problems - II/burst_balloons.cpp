// https://leetcode.com/problems/burst-balloons/

// Recursive

class Solution {
public:
	int get(vector<int> &nums, vector<vector<int> > &dp, int i, int j)
	{
		if (i > j)
			return 0;

		if (dp[i][j] != -1)
			return dp[i][j];

		for (int k = i; k <= j; ++k)
		{
			int rt = nums[j + 1];
			int lt = i > 0 ? nums[i - 1] : 1;
			int val = lt * nums[k] * rt;

			int lt_dp = get(nums, dp, i, k - 1);
			int rt_dp = get(nums, dp, k + 1, j);

			dp[i][j] = max(dp[i][j], lt_dp + val + rt_dp);
		}

		return dp[i][j];
	}

	int maxCoins(vector<int>& nums)
	{
		int n = nums.size();
		vector<vector<int> > dp(n, vector<int>(n, -1));

		nums.push_back(1);
		return get(nums, dp, 0, n - 1);
	}
};

// Iterative

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n));

		// for(int i = 0; i < n; ++i)
		// for(int j = i + 1; j < n; ++j)

		for (int l = 1; l <= n; ++l)
			for (int i = 0; i + l - 1 < n; ++i)
			{
				int j = i + l - 1;

				for (int k = i; k <= j; ++k)
				{
					int lt = i ? nums[i - 1] : 1;
					int rt = j + 1 < n ? nums[j + 1] : 1;
					int last = lt * rt * nums[k];

					int lt_dp = (i == k) ? 0 : dp[i][k - 1];
					int rt_dp = (j == k) ? 0 : dp[k + 1][j];


					dp[i][j] = max(dp[i][j], lt_dp + rt_dp + last);
				}
			}

		return dp[0][n - 1];
	}
};