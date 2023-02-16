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

int dp[100001][20], arr[100001];

int32_t main()
{
	FIO;
	int n; cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		dp[i][0] = 0;
	}

	// Pre-Process
	for (int i = 1; i <= n; ++i)
		for (int j = 1; i - (1 << j) >= 0; ++j)
		{
			int id = i - (1 << (j - 1));

			// [st,id], [id+1,i], arr[id+1] - arr[id]
			dp[i][j] = max({dp[id][j - 1], dp[i][j - 1], arr[id + 1] - arr[id]});
		}

	w(q)
	{
		int t, d; cin >> t >> d;

		int r = upper_bound(arr + 1, arr + n + 1, t) - arr - 1;
		// Last index id s.t. arr[id] <= t

		int l = r, beg = 1, end = r - 1;

		while (beg <= end)
		{
			int mid_l = beg + end >> 1;

			int j = log2(r - mid_l + 1);

			if (max(dp[r][j], dp[mid_l + (1 << j) - 1][j]) <= d)
				l = mid_l, end = mid_l - 1;
			else
				beg = mid_l + 1;
		}

		cout << l << '\n';
	}
	return 0;
}