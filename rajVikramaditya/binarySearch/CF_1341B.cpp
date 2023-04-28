#include<bits/stdc++.h>

using namespace std;
#define int long long int
int go(vector<int> &arr, int k) {
	int p=0;
	for(int i=1; i<k-1; i++) {
		if(arr[i] > arr[i+1] && arr[i] > arr[i-1]) p++;
	}
	int i=0, j=k-1;
	int m = p;
	while(j < arr.size()-1) {
		i++;
		if(arr[i] > arr[i+1] && arr[i] > arr[i-1]) p--;
		if(arr[j] > arr[j+1] && arr[j] > arr[j-1]) p++;
		j++;
		if(p > m) m=p;
	}
	return m;
}
signed main() {
	int tc; cin>>tc;
	while(tc--) {
		int n,k; cin>>n>>k;
		vector<int> arr(n);
		for(auto &it:arr) cin>>it;
		int p = go(arr,k);
		cout<<p+1<<" "<<p<<"\n";
	}
	return 0;
}