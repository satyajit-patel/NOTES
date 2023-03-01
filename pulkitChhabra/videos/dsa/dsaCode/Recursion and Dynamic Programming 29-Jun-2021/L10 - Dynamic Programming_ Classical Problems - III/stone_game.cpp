// https://leetcode.com/problems/stone-game/

class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		int n = piles.size();

		int pre[n];
		pre[0] = piles[0];
		for (int i = 1; i < n; ++i)
			pre[i] = pre[i - 1] + piles[i];

		int dp[n][n];

		for (int l = 1; l <= n; ++l)
			for (int i = 0; i + l - 1 < n; ++i)
			{
				if (l == 1)
					dp[i][i] = piles[i];
				else
				{
					int j = i + l - 1;
					int sum = i ? pre[j] - pre[i - 1] : pre[j];
					dp[i][j] = sum - min(dp[i][j - 1], dp[i + 1][j]);
				}
			}

		return 2 * dp[0][n - 1] > pre[n - 1];
	}
};