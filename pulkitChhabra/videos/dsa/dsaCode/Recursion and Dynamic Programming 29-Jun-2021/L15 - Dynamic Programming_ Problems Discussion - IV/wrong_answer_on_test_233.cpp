// https://codeforces.com/contest/1262/problem/F1

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int dp[2001][5001];
int arr[2002];

int32_t main()
{
	c_p_c();
	int n, k; cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	arr[n + 1] = arr[1];

	const int ZERO = n + 5;

	dp[0][ZERO] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int df = -i; df <= i; df++)
		{
			int j = df + ZERO;

			int cur = arr[i];
			int nxt = arr[i + 1];

			if (cur == nxt)
			{
				dp[i][j] = dp[i - 1][j] * k;
				dp[i][j] %= mod;
			}

			else
			{
				dp[i][j] = dp[i - 1][j] * (k - 2);
				dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}
		}
	}

	int ans = 0;

	for (int df = 1; df <= n; ++df)
	{
		int j = df + ZERO;
		ans += dp[n][j];
		ans %= mod;
	}

	cout << ans << '\n';

	return 0;
}