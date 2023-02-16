// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/gcd-strings/

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

int sum(long shift, long terms) {
	// sums 1 + 2^shift + 2^(2shift) + ... + 2^((terms-1) * shift)
	return (pwmd(2, shift * terms) + mod - 1) * pwmd(pwmd(2, shift) + mod - 1, mod - 2) % mod;
}

vi f(int a, int b)
{
	if (!(a % b))
		return {pwmd(2, a - 1), pwmd(2, b - 1)};

	vi part = f(b, a % b);

	return {(part[0]*sum(b, a / b) % mod * pwmd(2, a % b) + part[1]) % mod, part[0]};

}

int32_t main()
{
	FIO;
	w(t)
	{
		int a, b; cin >> a >> b;

		cout << f(a, b)[0] << '\n';
	}
	return 0;
}