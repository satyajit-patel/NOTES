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

int n;

void generate_permutations_1(vi &cur, vi &mark)
{
	if (cur.size() == n)
	{
		for (int i : cur)
			cout << i << ' ';
		cout << '\n';

		return;
	}

	for (int i = n; i >= 1; --i)
	{
		if (!mark[i])
		{
			// Do stuff
			cur.push_back(i);
			mark[i] = 1;

			generate_permutations_1(cur, mark);

			// Undo that stuff
			cur.pop_back();
			mark[i] = 0;
		}
	}
}

void generate_permutations_2(vi &arr, int i = 0)
{
	if (i == arr.size())
	{
		for (int cur : arr)
			cout << cur << ' ';
		cout << '\n';
		return;
	}

	for (int j = i; j < arr.size(); ++j)
	{
		swap(arr[i], arr[j]);
		generate_permutations_2(arr, i + 1);
		swap(arr[i], arr[j]);
	}
}

int32_t main()
{
	FIO;
	/*cin >> n; // [1......n]
	vector<int> cur, mark(n + 1);

	generate_permutations_1(cur, mark);*/

	vi arr = {1, 2, 3};
	generate_permutations_2(arr);

	return 0;
}