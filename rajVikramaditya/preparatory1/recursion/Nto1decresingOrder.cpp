#include<bits/stdc++.h>

using namespace std;
void print(int n) {
	//baseCase
	if(n < 1) return;

	//work
	cout<<n<<" ";

	//recursiveCase
	print(n-1);
}
int main() {
	cout<<"enter\n";
	//int n; cin>>n;
	//print(10);
	vector<int> v;
	int mi = *min_element(v.begin(), v.end());
	int ma = *max_element(v.begin(), v.end());
	cout<<mi<<"&"<<ma<<"\n";

	return 0;
}