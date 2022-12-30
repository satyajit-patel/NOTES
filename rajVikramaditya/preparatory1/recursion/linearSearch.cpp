#include<bits/stdc++.h>

using namespace std;
int print(vector<int> &arr, int i, int n, int target) {
	//baseCase
	if(i == n) return -1;
	if(arr[i] == target) return i;

	//recursiveCase&work
	return print(arr, i+1, n, target);
}
int main() {
	cout<<"enter\n";
	//int n; cin>>n;
	vector<int> arr = {0,10,20,30,40,50,60};
	int target = 30;
	int i=0, n=arr.size(); 
	int idx = print(arr,i,n, target);
	if(idx != -1) cout<<idx;
	else cout<<"not found\n";
	return 0;
}