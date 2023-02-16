// https://acm.timus.ru/problem.aspx?space=1&num=1017

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

int dp[501][501] = {};
//[i][j] means total i bricks used and largest step contains at most j bricks
//dp[i][j] represents number of ways to achieve the state i,j

int32_t main()
{
	FIO;
	int n; cin >> n;

	for (int i = 0; i <= n; ++i)
		dp[0][i] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			int ways_to_have_exactly_j = (j > i) ? 0 : dp[i - j][j - 1];
			dp[i][j] = dp[i][j - 1] + ways_to_have_exactly_j;
		}


	cout << dp[n][n - 1] << '\n';
	//because we want atleast 2 steps, that's why dp[n][n-1] and not dp[n][n];
	return 0;
}