#include<bits/stdc++.h>

void toBinary(int x, std::string& output) {
    // base case
    if(x <= 1) {
        output += std::to_string(x % 2);
        return;
    }
    
    // recursive case
    if(x >= 2) toBinary(x/2, output);
    output += std::to_string(x % 2);
}

void input() {
    int x = 18;
    std::string output = "";
    toBinary(x, output);
    std::cout<<x<<" i.e "<<output<<"\n";
    
    // is even odd
    if(x & 1) std::cout<<"odd\n";
    else std::cout<<"even\n";
    
    // is Kth bit is set
    int k = 1;
    if((x & (1 << k)) != 0) std::cout<<"yes "<<k<<"th bit is set\n";
    else std::cout<<"No "<<k<<"th bit is not set\n";
    
    // (x | (1 << k)  --> sets the Kth bit
    // (x ^ (1 << k)  --> toggles the Kth bit
    // (x & ~(1 << k) --> un sets the Kth bit
    std::cout<<(x & ~(1 << k))<<" new num after un setting "<<k<<"th bit\n";
    
    // is power of 2
    if((x & (x-1)) == 0) std::cout<<"yes power of 2\n";
    else std::cout<<"not power of 2\n";
    
    // swap without 3rd variable
    int n1 = 10, n2 = 20;
    std::cout<<"before swap "<<n1<<" "<<n2<<"\n";
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
    std::cout<<"after swap "<<n1<<" "<<n2<<"\n";
}

int main() {
	input();
	return 0;
}
