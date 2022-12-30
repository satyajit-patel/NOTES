#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>

bool cmp(int x, int y) {
	return x > y;
}
int main() {
	vi arr = {3,2,7,5,4,1};
	sort(arr.begin(), arr.end(), cmp);
	for(auto &it:arr) cout<<it<<" ";
	return 0;
}