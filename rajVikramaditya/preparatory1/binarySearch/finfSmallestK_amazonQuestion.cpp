#include<bits/stdc++.h>
#define endl "\n"
#define int long long int
#define vi vector<int>
using namespace std;

int go(vi &arr, int n, int mid) {
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += (arr[i]/mid);
	}
	return sum;
}
int bs(vi &arr, int n, int sum) {
	int low = 1; //arr[i]/0 will give runtime error
	int high = *max_element(arr.begin(), arr.end()) + 1;
	int ans = -1;
	while(low <= high) {
		int mid = (low+high)/2;
		int s = go(arr, n, mid);
		if(s <= sum) {
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	return ans;
}
signed main() {
	vi arr = {2,5,20,10,7,8,12};
	int n = arr.size();
	int sum = 12;
	int ans = bs(arr, n, sum);
	cout<<ans<<endl;
	return 0;
}