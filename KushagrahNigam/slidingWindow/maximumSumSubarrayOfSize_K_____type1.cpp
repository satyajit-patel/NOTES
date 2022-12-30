#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vi computePrefix(deque<int> arr) {
    int n = arr.size();
    vi prefix(n);
    for(int i=0; i<n; i++) {
        if(i == 0) {
            prefix[i] = arr[i];
            continue;
        }
        prefix[i] = arr[i]+prefix[i-1];
    }
    return prefix;
}
int maxSumSubarray(vi &arr, int n, int k) {
    deque<int> val;
    int maxi = INT_MIN;
    int i=0, j=0;
    while(j<n) {
        if(j-i+1 < k) {
            val.push_back(arr[j]);
	    j++;
            continue;
        }
        if(j-i+1 == k) {
            val.push_back(arr[j]);
            vi temp = computePrefix(val);
            maxi = max(maxi, temp[temp.size()-1]);
	    val.pop_front(); i++;//leave it & move forward
	    j++;
        }
    }
    return maxi;
}
int main() {
	int n,k; cin>>n>>k;
    vi arr(n);
    for(auto &it:arr) cin>>it;
	cout<<maxSumSubarray(arr, n, k);
    return 0;
}