#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>

struct myPair {
	int hi, bye;
};
int main() {
	vector<myPair> arr;
	for(int i=0; i<5; i++) {
		arr.push_back({i, i});
	}
	for(int i=0; i<5; i++) {
		cout<<arr[i].hi<<" "<<arr[i].bye<<"\n";
	}
	return 0;
}