#include<iostream>

using namespace std;
void print(int n) {
	//baseCase
	if(n > 10) return;

	//recursiveCase
	print(n+1);

	//work
	cout<<n<<" ";
}
int main() {
	cout<<"enter\n";
	//int n; cin>>n;
	print(1);
	return 0;
}