#include<bits/stdc++.h>
#define vi vector<int>
#define int long long int
#define endl "\n"
using namespace std;

int costOfPickingMidTimeElements(vi &arr, int n, int mid) {
	int sum = 0;
	vi dummyArray(n);
	for(int i=0; i<n; i++) dummyArray[i] = (arr[i] + (i+1) * mid);//i+1 bz in Q its given 1based indexing
	for(int i=0; i<mid; i++) sum += dummyArray[i];
	return sum;
}
pair<int, int> bs(vi &arr, int n, int s) {
	int low = 1, high = n, ans = -1;
	pair<int, int> p;
	while(low <= high) {
		int mid = (low+high)/2;
		int cost = costOfPickingMidTimeElements(arr, n, mid);
		if(cost <= s) {
			ans = cost;
			//p.first = mid;
			p.second = ans;
			low = mid+1;
		}
		else high = mid-1;
	}
	p.first = high;
	return p;
}
signed main() {
	int n,s; cin>>n>>s;
	vi arr(n);
	for(auto &it:arr) cin>>it;
	pair<int, int> p = bs(arr, n, s);
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}