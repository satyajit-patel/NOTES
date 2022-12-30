#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vi istN(vi &arr, int n, int k) {
	deque<int> dq;
	vector<int> ans;
	int i=0, j=0;
	while(j < n) {
		if(arr[j] < 0) dq.push_back(arr[j]);
		if(j-i+1 < k) {
			j++;
			continue;
		}
		if(j-i+1 == k) {
			if(dq.size() != 0) ans.push_back(dq.front());
			else ans.push_back(0);
			if(dq.front() == arr[i]) dq.pop_front();
			i++;
			j++;
		}
	}
	return ans;
}
int main() {
	int n,k; cin>>n>>k;
	vi arr(n);
	for(auto &it:arr) cin>>it;
	vi ans = istN(arr, n, k);
	for(auto &it:ans) cout<<it<<" ";
	return 0;
}