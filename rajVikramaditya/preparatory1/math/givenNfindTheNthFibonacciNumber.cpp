#include<iostream>

using namespace std;
int print(int n) {
	//baseCase
	if(n <= 1) return n;

	//recursiveCase&work
	int firstLast = print(n-1);
	int secondLast = print(n-2);
	return firstLast + secondLast;
}
int main() {
	cout<<"enter\n";
	//int n; cin>>n;
	cout<<print(3);
	return 0;
}