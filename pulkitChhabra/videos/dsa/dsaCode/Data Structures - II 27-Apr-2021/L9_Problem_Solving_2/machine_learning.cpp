// https://codeforces.com/problemset/problem/940/F
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
//#define int             long long
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

const int b = 2200;
int arr[100000], freq[200001], freq_freq[100001];
mii compress;
vector<vi> updates;

class query
{
public:
	int l, r, t, i;
	query(int lf, int rt, int time, int id)
	{
		l = lf - 1;
		r = rt - 1;
		t = time;
		i = id;
	}

	bool operator < (const query &q1)
	{
		return (l / b < q1.l / b) or
		       (l / b == q1.l / b and r / b < q1.r / b) or
		       (l / b == q1.l / b
		        and r / b == q1.r / b
		        and t < q1.t);
	}
};

void add(int i)
{
	int &fq = freq[arr[i]];
	freq_freq[fq]--;
	fq++;
	freq_freq[fq]++;
}

void remove(int i)
{
	int &fq = freq[arr[i]];
	freq_freq[fq]--;
	fq--;
	freq_freq[fq]++;
}

void do_or_undo(int i, int l, int r)
{
	int id = updates[i][0];

	if (l <= id and id <= r)
		remove(id);

	swap(arr[id], updates[i][1]);

	if (l <= id and id <= r)
		add(id);
}

int32_t main()
{
	FIO;
	int n, q; cin >> n >> q;



	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		compress[arr[i]] = 1;
	}

	// Compress the values
	int cur = 1;

	for (auto &p : compress)
		p.ss = (cur++);

	for (int i = 0; i < n; ++i)
		arr[i] = compress[arr[i]];


	vector<query> queries;
	int upd_id = -1;

	for (int i = 0; i < q; ++i)
	{
		int tp, l, r; cin >> tp;
		if (tp == 2)
		{
			int id, val; cin >> id >> val;

			if (compress.count(val))
				val = compress[val];

			else
			{
				compress[val] = (cur++);
				val = compress[val];
			}

			updates.pb({id - 1, val});
			upd_id++;
		}
		else
		{
			cin >> l >> r;
			queries.pb(query(l, r, upd_id, i));
		}
	}

	sort(queries.begin(), queries.end());

	vi val(q, -1);

	int l = 0, r = -1, t = -1, lim = 2 * sqrt(n) + 5;

	for (query &q : queries)
	{

		while (t < q.t)
			do_or_undo(++t, l, r);
		while (t > q.t)
			do_or_undo(t--, l, r);

		while (l > q.l)
			add(--l);
		while (r < q.r)
			add(++r);

		while (l < q.l)
			remove(l++);
		while (r > q.r)
			remove(r--);

		for (int i = 1; i <= lim; ++i)
			if (!freq_freq[i])
			{
				val[q.i] = i;
				break;
			}
	}

	for (int i : val)
		if (i != -1)
			cout << i << '\n';

	return 0;
}