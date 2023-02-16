// https://codeforces.com/problemsets/acmsguru/problem/99999/106
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


pii get_range(int i, int g, int fact, int s, int e)
{
	if (fact < 0)
		swap(s, e);

	int st = ceil((g * (s - i)) / (double)fact);
	int en = floor((g * (e - i)) / (double)fact);

	return {st, en};
}

int get_count_of_intersection(pii r1, pii r2)
{
	int st = max(r1.ff, r2.ff);
	int en = min(r1.ss, r2.ss);

	return (st <= en) ? en - st + 1 : 0;
}

int gcd_util(int a, int b) // a < b
{
	return b ? gcd_util(b, a % b) : a;
}

int gcd(int a, int b)
{
	return gcd_util(abs(a), abs(b));
}

pii extended_gcd_util(int a, int b)
{
	if (b == 0)
		return {1, 0};

	pii p = extended_gcd_util(b, a % b);
	int x = p.ff, y = p.ss;

	return {y, x - (a / b)*y};
}

pii extended_gcd(int a, int b)
{
	pii p = extended_gcd_util(abs(a), abs(b));

	if (a < 0)
		p.ff = -p.ff;

	if (b < 0)
		p.ss = -p.ss;

	return {p.ff, p.ss};
}

pii find_a_solution(int a, int b, int c) // ax + by = c
{
	if (a == 0 and b == 0)
		return c ? mp(INT_MAX, INT_MAX) : mp(0, 0);

	int g = gcd(a, b);

	if (c % g)
		return {INT_MAX, INT_MAX};

	pii p = extended_gcd(a, b); // ax + by = g

	p.ff *= c / g;
	p.ss *= c / g;

	return p;
}

int32_t main()
{
	FIO;
	int a, b, c, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

	c = -c;

	if (a == 0 and b == 0)
	{
		if (c == 0)
			cout << (x2 - x1 + 1)*(y2 - y1 + 1) << '\n';

		else
			cout << 0 << '\n';
	}

	else if (a == 0)
	{
		// by = c -> y = c/b

		if (c % b or c / b < y1 or c / b > y2)
			cout << 0 << '\n';

		else
			cout << x2 - x1 + 1 << '\n';

	}

	else if (b == 0)
	{
		// ax = c -> x = c/a

		if (c % a or c / a < x1 or c / a > x2)
			cout << 0 << '\n';

		else
			cout << y2 - y1 + 1 << '\n';

	}

	else
	{
		int g = gcd(a, b);

		if (c % g)
		{
			cout << 0 << '\n';
			return 0;
		}

		pii one = find_a_solution(a, b, c);

		pii r1 = get_range(one.ff, g, b, x1, x2);
		pii r2 = get_range(one.ss, g, -a, y1, y2);

		cout << get_count_of_intersection(r1, r2) << '\n';
	}

	return 0;
}