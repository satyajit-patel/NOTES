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

const int lim = 100001;
bitset < lim + 1 > prime;

int32_t main()
{
	FIO;
	prime.set();
	int n; cin >> n;

	if (n <= 2)
		cout << 1 << '\n';
	else
		cout << 2 << '\n';

	for (int i = 2; i <= n + 1; ++i)
	{
		if (prime[i])
		{
			cout << 1 << ' ';
			for (int j = i * i; j <= n + 1; j += i)
				prime[j] = 0;
		}

		else
			cout << 2 << ' ';
	}

	return 0;
}