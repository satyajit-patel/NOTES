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

int spf[1001];

void print_factors_aux(vector<pii> &prm, int i = 0, int cur = 1) // {p,power}
{
	if (i == prm.size())
	{
		cout << cur << '\n';
		return;
	}

	// Try all the powers of the current prime factor;
	int p = prm[i].ff, cur_p = 1;

	for (int pw = 0; pw <= prm[i].ss; ++pw)
	{
		print_factors_aux(prm, i + 1, cur * cur_p);
		cur_p *= p;
	}
}

void print_factors(int n)
{
	vector<pii> prm;

	while (n > 1)
	{
		int p = spf[n], pw = 0;

		while (!(n % p))
			n /= p, pw++;

		prm.pb({p, pw});
	}

	print_factors_aux(prm);
}

int32_t main()
{
	FIO;
	for (int i = 2; i <= 1000; ++i)
		if (!spf[i])
		{
			spf[i] = i;

			for (int j = i * i; j <= 1000; j += i)
				if (!spf[j])
					spf[j] = i;
		}

	print_factors(24);
	return 0;
}
