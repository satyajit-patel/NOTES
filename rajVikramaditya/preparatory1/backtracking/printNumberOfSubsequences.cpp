#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> ans;
vector<int> temp;
void print(vector<int> &arr, int i, int n) {
	//baseCase
	if(i == n) {
		ans.push_back(temp);
		return;
	}

	//recursiveCase&work
	temp.push_back(arr[i]); //pick&go
	print(arr, i+1, n);
	temp.pop_back(); //backtrack

	print(arr, i+1, n); //notPick&go
}
int main() {
	cout<<"enter\n";
	//int n; cin>>n;
	vector<int> arr = {3,2};
	print(arr,0,arr.size());
	for(int i=0; i<ans.size(); i++) {
		cout<<"[";
		for(int j=0; j<ans[i].size(); j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<"] ";
	}
	return 0;
}