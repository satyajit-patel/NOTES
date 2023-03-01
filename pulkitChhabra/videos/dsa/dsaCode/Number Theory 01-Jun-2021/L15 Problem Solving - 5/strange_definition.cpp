// https://codeforces.com/contest/1470/problem/B

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
	vi fp(1000001);

	for (int i = 2; i <= 1000000; ++i)
		if (!fp[i])
		{
			fp[i] = i;

			for (int j = i * i; j <= 1000000; j += i)
				fp[j] = i;
		}

	w(t)
	{
		int n; cin >> n;
		map<vi, int> cnt;

		for (int i = 1; i <= n; ++i)
		{
			int x; cin >> x;
			mii tmp;

			while (x > 1)
			{
				tmp[fp[x]] = 1 - tmp[fp[x]];
				x /= fp[x];
			}
			vi v;
			for (auto p : tmp)
				if (p.ss)
					v.pb(p.ff);

			cnt[v]++;
		}

		int mx_all = 0, even_sum = 0;

		for (auto p : cnt)
		{
			mx_all = max(mx_all, p.ss);

			if (p.ff.empty() or !(p.ss % 2))
				even_sum += p.ss;
		}

		w(q)
		{
			int w; cin >> w;

			if (w)
				cout << max(mx_all, even_sum) << '\n';
			else
				cout << mx_all << '\n';
		}
	}
	return 0;
}