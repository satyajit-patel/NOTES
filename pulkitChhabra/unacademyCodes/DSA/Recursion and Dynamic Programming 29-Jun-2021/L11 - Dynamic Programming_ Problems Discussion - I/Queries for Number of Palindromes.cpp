// https://codeforces.com/problemset/problem/245/H

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
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

int pal[5000][5000];
int num[5000][5000];
string s;

int isPal(int i, int j) // // if s[i..j] is palindrome, then 1, otherwise 0
{
	if (i == j)
		return 1;

	if (i + 1 == j)
		return (s[i] == s[j]);

	if (pal[i][j] != -1)
		return pal[i][j];

	return pal[i][j] = isPal(i + 1, j - 1) && (s[i] == s[j]) ? 1 : 0;
}

int getNum(int i, int j) // no. of palindromic substrings of s[i...j]
{
	if (i == j)
		return 1;

	if (i + 1 == j)
		return 2 + isPal(i, j);

	if (num[i][j] != -1)
		return num[i][j];

	return num[i][j] = getNum(i + 1, j) + getNum(i, j - 1) - getNum(i + 1, j - 1) + isPal(i, j);
}

int32_t main()
{
	FIO;
	memset(pal, -1, sizeof(pal));
	memset(num, -1, sizeof(num));

	cin >> s;

	w(q)
	{
		int i, j; cin >> i >> j;
		cout << getNum(i - 1, j - 1) << '\n';
	}

	return 0;
}