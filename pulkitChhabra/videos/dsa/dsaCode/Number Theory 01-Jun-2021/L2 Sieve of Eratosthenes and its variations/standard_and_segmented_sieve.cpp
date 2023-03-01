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

const int lim = 10000000;

int spf[lim + 1];

void pre()
{
	for (int i = 2; i <= lim; ++i)
	{
		if (!spf[i])
		{
			spf[i] = i;

			for (int j = i * i; j <= lim; j += i)
				if (!spf[j])
					spf[j] = i;
		}
	}
}

vector<pii> get_prime_factors(int x) // x >= 1 and x <= lim
{
	vector<pii> ans;

	while (x > 1)
	{
		int p = spf[x], cnt = 0;

		while (!(x % p))
			x /= p, cnt++;

		ans.pb({p, cnt});
	}

	return ans;
}

vi get_primes(int l, int r)
{
	// 1 <= l <= r <= 1e12
	// 1 <= r-l+1 <= 1e6

	if (l == 1)
		l++;

	vector<bool> prime(r - l + 1, 1);

	for (int i = 2; i * i <= r; ++i)
	{
		// first multiple of i which is >= l
		int num = ((l + i - 1) / i) * i;

		for (int j = max(i * i, num); j <= r; j += i)
			prime[j - l] = 0;
	}

	vi ans;

	for (int i = l; i <= r; ++i)
		if (prime[i - l])
			ans.pb(i);

	return ans;
}

int32_t main()
{
	FIO;
	pre();

	/*vi pre(lim + 1);

	for (int i = 2; i <= lim; ++i)
		pre[i] = (spf[i] == i) ? pre[i - 1] + i : pre[i - 1];

	w(t)
	{
		int n; cin >> n;
		cout << pre[n] << '\n';
	}*/

	vi ans = get_primes(1, 15);

	for (int p : ans)
		cout << p << ' ';


	return 0;
}