#include <iostream>

using namespace std;
int main() {
	for(int i=0; i<5; i++) {
		static int sum = 0;
		sum += 5;
		cout<<sum<<" ";
	}
	return 0;
}