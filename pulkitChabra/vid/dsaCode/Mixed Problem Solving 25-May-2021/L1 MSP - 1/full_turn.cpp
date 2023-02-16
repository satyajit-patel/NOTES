// https://codeforces.com/contest/1468/problem/F

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
	w(t)
	{
		map<vi, int> cnt;

		w(n)
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			int dx = x2 - x1;
			int dy = y2 - y1;

			if (!dx)
				cnt[ {1, 0, dy > 0}]++;

			else if (!dy)
				cnt[ {0, 1, dx > 0}]++;

			else
			{
				int gc = __gcd(abs(dx), abs(dy));

				dx /= gc, dy /= gc;
				int third = dy > 0;

				if (dx * dy > 0)
					dx = abs(dx), dy = abs(dy);

				else
					dx = -abs(dx), dy = abs(dy);

				cnt[ {dy, dx, third}]++;
			}
		}

		int ans = 0;

		for (auto p : cnt)
		{
			vi v = p.ff;
			v[2] = 1 - v[2];

			if (cnt.count(v))
				ans += p.ss * cnt[v];
		}

		cout << ans / 2 << '\n';
	}
	return 0;
}
