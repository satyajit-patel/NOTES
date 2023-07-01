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

int gcd_util(int a, int b) // a < b
{
	return b ? gcd_util(b, a % b) : a;
}

int gcd(int a, int b)
{
	return gcd_util(abs(a), abs(b));
}

pii extended_gcd_util(int a, int b)
{
	if (b == 0)
		return {1, 0};

	pii p = extended_gcd_util(b, a % b);
	int x = p.ff, y = p.ss;

	return {y, x - (a / b)*y};
}

pii extended_gcd(int a, int b)
{
	pii p = extended_gcd_util(abs(a), abs(b));

	if (a < 0)
		p.ff = -p.ff;

	if (b < 0)
		p.ss = -p.ss;

	return {p.ff, p.ss};
}

int32_t main()
{
	FIO;
	return 0;
}