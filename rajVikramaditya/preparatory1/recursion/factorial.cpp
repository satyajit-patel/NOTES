#include<iostream>

using namespace std;
int print(int n) {
	//baseCase
	if(n <= 1) return 1;

	//recursiveCase&work
	return n * print(n-1);
}
int main() {
	cout<<"enter\n";
	//int n; cin>>n;
	cout<<print(5);
	return 0;
}