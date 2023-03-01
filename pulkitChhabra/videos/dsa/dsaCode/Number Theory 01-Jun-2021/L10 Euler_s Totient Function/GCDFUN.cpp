// https://www.codechef.com/PLIN2020/problems/GCDFUN

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

int sv[1000001] = {};

int pwmd(int a, int n)
{
	if (!n)
		return 1;
	int pt = pwmd(a, n / 2);
	pt *= pt, pt %= mod;
	if (n & 1)
		pt *= a, pt %= mod;
	return pt;
}

int32_t main()
{
	c_p_c();

	vi prm;

	for (int i = 2; i <= 1000000; ++i)
		if (!sv[i])
		{
			prm.pb(i);
			sv[i] = i;
			for (int j = i * i; j <= 1000000; j += i)
				if (!sv[j])
					sv[j] = i;
		}

	w(t)
	{
		int n; cin >> n;

		if (n == 1)
		{
			cout << 1 << '\n';
			continue;
		}

		int num = n;
		mii fct;

		for (auto el : prm)
		{
			if (num == 1)
				break;

			while (!(num % el))
				fct[el]++, num /= el;
		}

		if (num > 1)
			fct[num] = 1;

		vi fc;

		for (auto el : fct)
		{
			//cout << el.ff << ' ' << el.ss << '\n';
			int fv = (mod + 1 - pwmd(el.ff % mod, mod - 2)) % mod;
			fv = (fv * el.ss) % mod;
			fc.pb(fv);
		}
		//cout << '\n';

		n = fct.size();
		num = 1 << n;
		int ans = 0;

		for (int m = 0; m < num; ++m)
		{
			int cur = 1;

			for (int i = 0; i < n; ++i)
				if ((m >> i) & 1)
					cur = (cur * fc[i]) % mod;

			ans += cur;
			ans %= mod;
		}

		cout << ans << '\n';

	}
	return 0;
}