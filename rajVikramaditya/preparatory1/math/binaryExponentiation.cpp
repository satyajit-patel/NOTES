#include<iostream>
#define int long long int
using namespace std;
int M = 1e9+7;

int BE(int base, int power) {
	int ans = 1;
	while(power) {
		if(power%2) {
			ans = (ans*base)%M;
			power -= 1;
		}
		else {
			base = (base*base)%M;
			power /= 2;
		}
	}
	return ans;
}
signed main() {
	cout<<BE(2,10);
	return 0;
}
