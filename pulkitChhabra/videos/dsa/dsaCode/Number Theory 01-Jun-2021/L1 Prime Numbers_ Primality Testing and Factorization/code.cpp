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

bool check_prime(int n) // n is positive
{
	if (n == 1)
		return false;

	for (int i = 2; i * i <= n; ++i)
		if (!(n % i))
			return false;

	return true;
}

vi get_divisors(int n)
{
	vi ans;
	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i)
			continue;

		ans.pb(i);

		if (i * i != n)
			ans.pb(n / i);
	}

	return ans; // Note that 'ans' won't be in sorted order
}

vector<pii> get_prime_factors(int n)
{
	vector<pii> ans;

	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i)
			continue;

		int p = 0;

		while (!(n % i))
			n /= i, p++;

		ans.pb({i, p});
	}

	if (n > 1)
		ans.pb({n, 1});

	return ans;
}

int32_t main()
{
	FIO;

	int n; cin >> n;
	auto div = get_divisors(n);
	auto prm = get_prime_factors(n);

	cout << check_prime(n) << '\n';

	for (int i : div)
		cout << i << ' ';
	cout << '\n';

	for (pii p : prm)
		cout << p.ff << ' ' << p.ss << '\n';

	return 0;
}