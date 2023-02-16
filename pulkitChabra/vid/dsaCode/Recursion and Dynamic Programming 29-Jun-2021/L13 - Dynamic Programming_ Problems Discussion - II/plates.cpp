// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb#problem

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
	FIO;
	int tc; cin >> tc;
	for (int tnum = 1; tnum <= tc; ++tnum)
	{
		int n, k, p; cin >> n >> k >> p;
		vector<vi> dp(n + 1, vi(p + 1)), pre(n + 1, vi(k + 1));

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= k; ++j)
			{
				int x; cin >> x;
				pre[i][j] = pre[i][j - 1] + x;
			}
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= p; ++j)
				for (int l = 0; l <= min(k, j); ++l)
					dp[i][j] = max(dp[i][j], pre[i][l] + dp[i - 1][j - l]);

		cout << "Case #" << tnum << ": " << dp[n][p] << '\n';
	}
	return 0;
}