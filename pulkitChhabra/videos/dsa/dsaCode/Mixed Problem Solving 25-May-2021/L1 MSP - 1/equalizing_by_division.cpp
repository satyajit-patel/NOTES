// https://codeforces.com/contest/1213/problem/D2

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
#define MX              200005
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

int32_t main()
{
	c_p_c();
	int n, k; cin >> n >> k;
	map<int, vi> cost;

	for (int i = 0; i < n; ++i)
	{
		int value; cin >> value;
		int cur = 0;

		while (value)
		{
			cost[value].pb(cur);
			cur++;
			value /= 2;
		}

		cost[0].pb(cur);
	}

	int ans = inf;

	for (auto &el : cost)
	{
		if (el.ss.size() < k)
			continue;

		sort(el.ss.begin(), el.ss.end());

		int cur = 0;

		for (int i = 0; i < k; ++i)
			cur += el.ss[i];

		ans = min(ans, cur);
	}

	cout << ans << '\n';

	return 0;
}
