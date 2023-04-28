#include<bits/stdc++.h>

using namespace std;
bool print(string s, int i, int j) {
	//baseCase
	if(i >= j) return true;
	if(s[i] != s[j]) return false;

	//recursiveCase&work
	return print(s, i+1, j-1);
}
int main() {
	cout<<"enter\n";
	//int n; cin>>n;
	string s = "madam";
	int i=0, j=s.size()-1;
	bool flag = print(s,i,j);
	if(flag == true) cout<<"yes\n";
	else cout<<"no\n";
	return 0;
}