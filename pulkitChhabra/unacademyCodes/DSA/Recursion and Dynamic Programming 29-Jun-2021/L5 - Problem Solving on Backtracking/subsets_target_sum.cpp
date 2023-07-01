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


void print_all_subsets(vi &arr, vi &cur, int target, int i = 0, int sum = 0)
{
	if (sum > target)
		return;

	if (target == sum)
	{
		for (int i : cur)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	if (i == arr.size())
		return;

	// Include the current number;
	cur.pb(arr[i]);
	print_all_subsets(arr, cur, target, i + 1, sum + arr[i]);
	cur.pop_back();

	// Don't include it;
	print_all_subsets(arr, cur, target, i + 1, sum);
}

int32_t main()
{
	FIO;
	int n, k; cin >> n >> k;
	vi arr(n), cur;

	for (int &i : arr)
		cin >> i;

	print_all_subsets(arr, cur, k);
	return 0;
}