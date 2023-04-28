#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int istOccurance(vi &arr, int target) {
	int n = arr.size(), low = 0, high= n-1, ans = -1;
	while(low <= high) {
		int mid = (low+high)/2;
		if(arr[mid] == target) {
			ans = mid;
			high = mid-1;
		}
		else if(arr[mid] < target) low = mid+1;
		else high = mid-1;
	}
	return ans;
}
bool bs(vi &arr, int target) {
	int n = arr.size(), low = 0, high= n-1;
	while(low <= high) {
		int mid = (low+high)/2;
		if(arr[mid] == target) return true;
		else if(arr[mid] < target) low = mid+1;
		else high = mid-1;
	}
	return false;
}
int main() {
	vector<int> arr = {1,2,2,2,2,5,5,5};

	bool res = binary_search(arr.begin(), arr.end(), 2);
	if(res) cout<<"exist\n";
	else cout<<"doesn't exist\n";

	res = bs(arr, 10);
	if(res) cout<<"exist\n";
	else cout<<"doesn't exist\n";

	auto it = lower_bound(arr.begin(), arr.end(), 21); //iterator != index
	if(it != arr.end()) cout<<*it<<"\n";
	else cout<<"doesn't exist\n";

	int idx = lower_bound(arr.begin(), arr.end(), 2)-arr.begin(); //>=
	if(idx != arr.size()) cout<<"index is "<<idx<<" ans element is "<<arr[idx]<<"\n";
	else cout<<"doesn't exist\n";

	idx = istOccurance(arr, 2);
	if(idx != -1) cout<<"index is "<<idx<<" ans element is "<<arr[idx]<<"\n";
	else cout<<"doesn't exist\n";

	return 0;
}