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
	int pre, end;
	map<char, node*> child;
	node() : pre(0), end(0) {}
};

class Trie
{
	node *root;

public:
	Trie(): root(new node) {}

	void insert(const string &s)
	{
		node *cur = root;
		for (char ch : s)
		{
			cur->pre++;

			if (!(cur->child).count(ch))
				cur->child[ch] = new node;

			cur = cur->child[ch];
		}

		// For the last node
		cur->pre++;
		cur->end++;
	}

	vector<int> count(const string &s) // number of times s is present in the DS
	{
		node *cur = root;
		int n = s.size();
		vi v(n);

		for (int i = 0; i < n; ++i)
		{
			char ch = s[i];

			if (!(cur->child).count(ch))
				return v;

			cur = cur->child[ch];
			v[i] = cur->end;
		}

		return v;
	}
};

int32_t main()
{
	FIO;
	Trie t1, t2;
	w(q)
	{
		int tp;
		string s;
		cin >> tp >> s;

		if (tp == 1)
		{
			t1.insert(s);
			reverse(s.begin(), s.end());
			t2.insert(s);
		}

		else
		{
			vi pre = t1.count(s);
			reverse(s.begin(), s.end());
			vi suf = t2.count(s);
			reverse(suf.begin(), suf.end());

			string can = "NO";
			int n = s.length();

			bool equal = (n % 2 == 0) and s.substr(0, n / 2) == s.substr(n / 2);

			for (int i = 0; i + 1 < n; ++i)
			{
				if (i + 1 == n - 1 - i and equal)
				{
					if (pre[i] > 1)
					{
						can = "YES";
						break;
					}
				}

				else if (pre[i] and suf[i + 1])
				{
					can = "YES";
					break;
				}
			}

			cout << can << '\n';
		}
	}
	return 0;
}