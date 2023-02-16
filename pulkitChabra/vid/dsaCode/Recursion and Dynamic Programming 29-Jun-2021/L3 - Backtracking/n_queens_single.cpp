// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/n-queensrecursion-tutorial/

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
int queen[10][10];

bool under_attack(int r, int c)
{
	for (int i = 0; i < r; ++i)
		if (queen[i][c])
			return true;

	for (int j = 0; j < c; ++j)
		if (queen[r][j])
			return true;

	for (int i = r, j = c; min(i, j) >= 0; i--, j--)
		if (queen[i][j])
			return true;

	for (int i = r, j = c; i >= 0 and j < n; i--, j++)
		if (queen[i][j])
			return true;

	return false;
}

bool backtrack(int r = 0)
{
	if (r == n)
		return true;

	for (int c = 0; c < n; ++c)
		if (!under_attack(r, c))
		{
			queen[r][c] = 1;
			bool done = backtrack(r + 1);

			if (done)
				return true;

			queen[r][c] = 0;
		}

	return false;
}

int32_t main()
{
	FIO;
	cin >> n;
	bool check = backtrack();

	if (check)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j  < n; ++j)
				cout << queen[i][j] << ' ';
			cout << '\n';
		}

	}

	else
		cout << "Not possible\n";
	return 0;
}