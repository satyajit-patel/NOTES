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

int level[1001] = {};
int subtr[1001] = {};

void dfs(int cur, int par, vi *adj)
{
	cout << cur << ' ';

	level[cur] = level[par] + 1;
	subtr[cur] = 1;

	for (int nb : adj[cur])
	{
		if (nb == par)
			continue;

		dfs(nb, cur, adj);
		subtr[cur] += subtr[nb];
	}
}

int32_t main()
{
	FIO;
	int n; cin >> n;
	vi *adj = new vi[n + 1];

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0, adj);
	cout << '\n';

	for (int i = 1; i <= n; ++i)
		cout << i << '\t' << level[i] << '\n';

	return 0;
}
