//https://www.spoj.com/problems/PRIME1/

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

const int lim = 32000;
bitset<lim> b;

vi primes;

void countPrimes(int l, int r)
{
	vector<bool> isPrime(r - l + 1, 1);

	if (l == 1)
		isPrime[0] = 0;

	for (int p : primes)
	{
		if (p * p > r)
			break;

		int num = (l + p - 1) / p * p;

		for (int j = max(num, p * p); j <= r; j += p)
			isPrime[j - l] = 0;
	}

	int ans = 0;

	for (int i = l; i <= r; ++i)
		if (isPrime[i - l])
			cout << i << '\n';

	cout << '\n';
}

int32_t main()
{
	FIO;
	b.set();

	for (int i = 2; i <= lim; ++i)
		if (b[i])
		{
			primes.pb(i);
			for (int j = i * i; j <= lim; j += i)
				b[j] = 0;
		}

	w(T)
	{
		int l, r; cin >> l >> r;
		countPrimes(l, r);
	}
	return 0;
}