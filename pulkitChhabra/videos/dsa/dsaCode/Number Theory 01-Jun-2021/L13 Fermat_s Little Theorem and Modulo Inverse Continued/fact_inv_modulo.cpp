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

const int mx = 1000000;
int fct[mx + 1], inv[mx + 1];

int pwmd(int a, int n = mod - 2)
{
	if (!n)
		return 1;
	int pt = pwmd(a, n / 2);
	pt *= pt, pt %= mod;
	if (n & 1)
		pt *= a, pt %= mod;
	return pt;
}

void pre1()
{
	fct[0] = inv[0] = 1;

	for (int i = 1; i <= mx; ++i)
		fct[i] = fct[i - 1] * i % mod, inv[i] = pwmd(fct[i]);
}

void pre2()
{
	fct[0] = 1;

	for (int i = 1; i <= mx; ++i)
		fct[i] = fct[i - 1] * i % mod;

	inv[mx] = pwmd(fct[mx]);

	for (int i = mx - 1; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}

int nCr(int n, int r)
{
	return r > n ? 0 : fct[n] * (inv[r] * inv[n - r] % mod) % mod;
}

int32_t main()
{
	FIO;
	pre2();
	w(t)
	{
		int n, r; cin >> n >> r;
		cout << nCr(n, r) << '\n';
	}
	return 0;
}