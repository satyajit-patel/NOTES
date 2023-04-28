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

int w[41], p[41], v[41];

vector<pii> v1;
vector<pii> v2;

int32_t main()
{
	c_p_c();
	w(t)
	{
		int n; cin >> n;
		v1.clear();
		v2.clear();

		for (int i = 0; i < n; ++i)
			cin >> w[i] >> p[i] >> v[i];

		int final = 0;

		int num = pw(2, n / 2);

		for (int msk = 0; msk < num; ++msk)
		{
			int wt = 0;
			int prf = 0;

			for (int i = 0; i < n / 2; ++i)
			{
				if ( !((msk >> i) & 1) || wt > w[i])
				{
					continue;
				}

				wt += p[i];
				prf += v[i];
			}

			v1.pb({wt, prf});
		}

		int sz = n - n / 2;

		for (int i = n / 2; i < n; ++i)
		{
			w[i - n / 2] = w[i];
			p[i - n / 2] = p[i];
			v[i - n / 2] = v[i];
		}

		num = pw(2, sz);

		for (int msk = 0; msk < num; ++msk)
		{
			int wt = 0;
			int prf = 0;
			int max_buffer_allowed = inf;

			for (int i = 0; i < sz; ++i)
			{
				if ( !((msk >> i) & 1) || wt > w[i])
				{
					continue;
				}

				max_buffer_allowed = min(max_buffer_allowed, w[i] - wt);

				wt += p[i];
				prf += v[i];

			}

			v2.pb({max_buffer_allowed, prf});
		}

		sort(v2.begin(), v2.end());

		sz = v2.size();

		vi suf_max(sz + 1, 0);

		for (int i = sz - 1; i >= 0; --i)
			suf_max[i] = max(suf_max[i + 1], v2[i].ss);

		/*for(int i=0;i<sz;++i)
			cout<<v2[i].ff<<' ';

		cout<<'\n';*/

		for (auto el : v1)
		{
			pii tmp = mp(el.ff, -1);
			int id = lower_bound(v2.begin(), v2.end(), tmp) - v2.begin();

			//cout<<final<<'\n';
			//cout<<el.ff<<' '<<el.ss<<' '<<id<<'\n';

			final = max(final, el.ss + suf_max[id]);
		}

		cout << final << '\n';
	}
	return 0;
}