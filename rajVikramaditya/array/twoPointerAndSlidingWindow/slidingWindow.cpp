#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

/*
int go(vi &arr, int k) {
	//step1
	int s=0, m=0;
	for(int i=0; i<k; i++) {
		s += arr[i];
	}
	m=s;

	//step2
	int n=arr.size();
	int i=0,j=k-1;
	while(j < n-1) {
		s -= arr[i++]; //firstLeave then moveForward
		s += arr[++j]; //firstCome then take
		if(s > m) m=s; 
	}
	return m;
} 
*/

int go(vi &arr, int k) {
	int maxSum = INT_MIN;
	int curSum = 0;
	for(int i=0; i<k; i++) curSum += arr[i];
	maxSum = std::max(maxSum, curSum);
	int i = 0;
	int j = k;
	int N = arr.size();
	while(i < N && j < N) {
	    curSum += arr[j++];
	    curSum -= arr[i++];
	    maxSum = std::max(maxSum, curSum);
	}
	return maxSum;
}

int main() {
	vi arr = {1,2,3,4,5,6,7,8};
	int k = 3;
	cout<<go(arr, k);
	return 0;
}