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

	node *actual_erase_aux(node *cur, const string &s, int i)
	{
		//delete s[i...n-1] out of this cur node.
		cur->pre--;
		int n = s.length();

		if (i == n - 1) // this is the last character
			cur->end--;

		else
		{
			cur->child[s[i + 1]] = actual_erase_aux(cur->child[s[i + 1]], s, i + 1);

			if (cur->child[s[i + 1]] == NULL)
				(cur->child).erase(s[i + 1]);
		}

		if (cur->pre)
			return cur;

		delete cur;
		return NULL;
	}

	void sorted_aux(node *cur, string &s, vector<string> &ans)
	{
		for (int times = 0; times < (cur->end); ++times)
			ans.pb(s);

		for (auto &p : cur->child)
		{
			s += p.ff;
			sorted_aux(p.ss, s, ans);
			s.pop_back();
		}
	}

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

	int erase(const string &s)
	{
		if (!count(s))
			return 0;

		node *cur = root;
		for (char ch : s)
		{
			cur->pre--;
			cur = cur->child[ch];
		}

		// For the last node
		cur->pre--;
		cur->end--;

		return 1;
	}

	int actual_erase(const string &s) // Assuming non-empty strings
	{
		if (!count(s))
			return 0;

		auto &cur = root->child[s[0]];
		root->pre--;

		cur = actual_erase_aux(cur, s, 0);
		return 1;
	}

	int count(const string &s) // number of times s is present in the DS
	{
		node *cur = root;

		for (char ch : s)
		{
			if (cur->pre == 0)
				return 0;

			if (!(cur->child).count(ch))
				return 0;

			cur = cur->child[ch];
		}

		return cur->end;
	}

	vector<string> sorted()
	{
		vector<string> ans;

		string s;
		sorted_aux(root, s, ans);

		return ans;
	}
};

int32_t main()
{
	FIO;
	vector<string> v = {"the", "a", "there", "answer", "any", "bye", "by", "their", "any"};
	Trie t;

	for (auto s : v)
		t.insert(s);

	t.actual_erase("answer");
	cout << t.count("any") << '\n';

	auto vec = t.sorted();

	for (auto s : vec)
		cout << s << '\n';
	return 0;
}