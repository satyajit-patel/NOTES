// https://codeforces.com/contest/1221/problem/D

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
#define MX              300005
#define mod             1000000007
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

int a[300005], b[300005], dp[300005][3];

int32_t main()
{
	c_p_c();
	w(t)
	{
		int n; cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> a[i] >> b[i];

		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = 2 * b[0];

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				int mn = inf;

				for (int p = 0; p < 3; ++p)
					if (a[i - 1] + p != a[i] + j)
						mn = min(mn, dp[i - 1][p] + j * b[i]);

				dp[i][j] = mn;
			}
		}

		int ans = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

		cout << ans << '\n';

	}
	return 0;
}