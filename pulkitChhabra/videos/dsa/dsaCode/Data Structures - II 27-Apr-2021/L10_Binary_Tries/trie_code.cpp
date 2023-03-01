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

class node
{
public:
	node *child[2];
	int cnt[2];
	node()
	{
		child[0] = child[1] = NULL;
		cnt[0] = cnt[1] = 0;
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

			cur->cnt[b]++;
			cur = cur->child[b];
		}
	}

	void erase(int num) // assume that it is present
	{
		vector<node*> del;
		node *cur = root;

		for (int i = 29; i >= 0; --i)
		{
			int b = (num >> i) & 1;

			cur->cnt[b]--;
			node *go_to = cur->child[b];

			if (cur->cnt[b] == 0)
			{
				cur->child[b] = NULL;
				del.pb(go_to);
			}

			cur = go_to;
		}

		for (int i = 0; i < del.size(); ++i)
			delete del[i];
	}

	int count(int num)
	{
		node *cur = root;

		for (int i = 29; i >= 1; --i)
		{
			int b = (num >> i) & 1;

			if (cur->child[b] == NULL)
				return 0;

			cur = cur->child[b];
		}

		return cur->cnt[num & 1];
	}
};

int32_t main()
{
	FIO;
	Trie t;

	for (int i = 1; i <= 1000; ++i)
		t.insert(i);

	t.insert(1000);
	t.erase(1000);
	t.erase(1000);

	cout << t.count(1000);
	return 0;
}