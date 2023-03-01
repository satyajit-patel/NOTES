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

// https://www.hackerrank.com/challenges/maximum-xor/problem

class node
{
public:
	node *child[2];
	node()
	{
		child[0] = child[1] = NULL;
	}
};

class Trie // numbers inserted <= 1e9 (bits <= 30)
{
	node *root = new node;
public:
	void insert(int num)
	{
		node *cur = root;

		for (int i = 29; i >= 0; --i)
		{
			int b = (num >> i) & 1;

			if (cur->child[b] == NULL)
				cur->child[b] = new node;

			cur = cur->child[b];
		}
	}

	int max_xor(int num)
	{
		node *cur = root;
		int ans = 0;

		for (int i = 29; i >= 0; --i)
		{
			int b = (num >> i) & 1;

			if (cur->child[1 - b])
				ans += (1 << i), cur = cur->child[1 - b];
			else
				cur = cur->child[b];
		}

		return ans;
	}
};

int32_t main()
{
	FIO;
	Trie t;

	w(n)
	{
		int x; cin >> x;
		t.insert(x);
	}

	w(m)
	{
		int x; cin >> x;
		cout << t.max_xor(x) << '\n';
	}
	return 0;
}