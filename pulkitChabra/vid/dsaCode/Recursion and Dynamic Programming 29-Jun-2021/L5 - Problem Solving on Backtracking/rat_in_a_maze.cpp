// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
	void findPathUtil(vector<vector<int>> &m, int n, vector<string> &ans, string &cur, vector<vector<bool> > vis, int i = 0, int j = 0)
	{
		if (min(i, j) < 0 or max(i, j) >= n or m[i][j] == 0 or vis[i][j])
			return;

		if (i == n - 1 and j == n - 1)
		{
			ans.push_back(cur);
			return;
		}

		vis[i][j] = 1;

		string poss = "DLRU";
		int di[] = {1, 0, 0, -1};
		int dj[] = {0, -1, 1, 0};

		for (int k = 0; k < 4; ++k)
		{
			cur += poss[k];
			findPathUtil(m, n, ans, cur, vis, i + di[k], j + dj[k]);
			cur.pop_back();
		}

		vis[i][j] = 0;
	}
public:
	vector<string> findPath(vector<vector<int>> &m, int n) {
		// Your code goes here
		vector<string> ans;
		string cur;
		vector<vector<bool> > vis(n, vector<bool>(n));

		findPathUtil(m, n, ans, cur, vis);

		if (ans.empty())
			ans = {"-1"};

		return ans;
	}
};