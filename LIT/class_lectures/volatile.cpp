#include<iostream>

using namespace std;
int main() {
	//const int x = 10; //this wouldn't change the value  
	volatile const int x = 10; //this will do 
	cout<<x<<endl;
	int *p = (int *)&x;
	(*p)++;
	cout<<x<<endl;
	return 0;
}