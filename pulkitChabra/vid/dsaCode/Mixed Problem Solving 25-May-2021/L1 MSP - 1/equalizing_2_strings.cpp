// https://codeforces.com/contest/1256/problem/F
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;

		inv_count = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left,
          int mid, int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int32_t main()
{
	c_p_c();
	w(t)
	{
		int n; cin >> n;
		int fq[26] = {};
		int mult = 0;
		string s, t; cin >> s >> t;

		for (int i = 0; i < n; ++i)
		{
			fq[s[i] - 'a']++;
			if (fq[s[i] - 'a'] > 1)
				mult = 1;
		}

		for (int i = 0; i < n; ++i)
			fq[t[i] - 'a']--;

		int can = 1;

		for (int i = 0; i < 26; ++i)
			if (fq[i] != 0)
				can = 0;

		mk(arr, n, int);

		for (int i = 0; i < n; ++i)
			arr[i] = s[i] - 'a';

		int inv1 = mergeSort(arr, n);
		inv1 %= 2;

		for (int i = 0; i < n; ++i)
			arr[i] = t[i] - 'a';

		int inv2 = mergeSort(arr, n);
		inv2 %= 2;

		if ((!mult) && (inv1 != inv2))
			can = 0;

		if (can)
			cout << "YES\n";
		else
			cout << "NO\n";


	}
	return 0;
}
