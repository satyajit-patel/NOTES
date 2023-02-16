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

int dp[100000][20], arr[100000], lg[100001];

// https://www.spoj.com/problems/RMQSQ/

int32_t main()
{
	FIO;
	int n; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		dp[i][0] = arr[i];
		lg[i + 1] = log2(i + 1);
	}

	// Pre-Process
	for (int i = n - 1; i >= 0; --i)
		for (int j = 1; i + (1 << j) - 1 < n; ++j)
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);

	w(q)
	{
		int l, r; cin >> l >> r;
		int j = lg[r - l + 1];

		cout << min(dp[l][j], dp[r - (1 << j) + 1][j]) << '\n';
	}
	return 0;
}