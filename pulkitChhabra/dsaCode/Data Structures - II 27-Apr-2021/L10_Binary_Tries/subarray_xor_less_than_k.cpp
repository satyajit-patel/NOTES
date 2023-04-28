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


// https://www.spoj.com/problems/SUBXOR/

class node
{
public:
	int cnt[2];
	node *child[2];
	node()
	{
		cnt[0] = cnt[1] = 0;
		child[0] = child[1] = NULL;
	}
};

class Trie
{
	node *root;
public:
	Trie()
	{
		root = new node();
	}

	void insert(int num) // num <= 1e5
	{
		node *cur = root;
		for (int i = 19; i >= 0; --i)
		{
			int b = (num >> i) & 1;

			if (!cur->child[b])
				cur->child[b] =  new node();

			cur->cnt[b]++;
			cur = cur->child[b];
		}
	}

	int count(int num, int k)
	{
		node *cur = root;
		int ans = 0;

		for (int i = 19; i >= 0; --i)
		{
			int kb = (k >> i) & 1;
			int zero = (num >> i) & 1;

			if (kb)
				ans += cur->cnt[zero];

			if (cur->child[zero ^ kb])
				cur = cur->child[zero ^ kb];

			else
				break;
		}

		return ans;
	}
};

int32_t main()
{
	//FIO;
	w(t)
	{
		int n, k; cin >> n >> k;
		Trie t;
		int pre = 0, ans = 0;
		t.insert(pre);

		for (int i = 1; i <= n; ++i)
		{
			int x; cin >> x;
			pre ^= x;

			ans += t.count(pre, k);
			t.insert(pre);
		}

		cout << ans << '\n';
	}
	return 0;
}