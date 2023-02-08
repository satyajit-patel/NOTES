#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false); cin.tie(NULL);

// ----------------------------------------------------------------------------------------------------

// link:- 

vector<int> prime;
void preComputePrime(int n) {
    prime.resize(n+1, 1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i=2; i<=n; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=n; j+=i) prime[j] = 0;
        }
    }
}

void printPrimeFrom1ToN(int n) {
    for(int i=0; i<=n; i++) if(prime[i]) cout<<i<<" ";
    cout<<endl;
}

string isPrime(int n) {
    preComputePrime(n);
    if(prime[n]) return "YES " + std::to_string(n) + " is prime";
    return "NO " + std::to_string(n) + " is not prime";
}

int fact(int n) {
    if(n <= 1) return 1;
    return n * fact(n-1);
}

string checkEvenOdd(int n) {
    if(n % 2 == 0) return "it is an even number";
    return "it is a odd number";
}

float areaOfCircle(int radius) {
    float ans = M_PI * (radius * radius);
    return ans;
}

void homeWork(int n) {
    printf("area is %.2f\n", areaOfCircle(n));
    cout<<checkEvenOdd(n)<<endl;
    cout<<"factorial is "<<fact(n)<<endl;
    cout<<isPrime(n)<<endl;
    printPrimeFrom1ToN(n);
}

void input() {
    int n; cin>>n;
    homeWork(n);
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // IOS
    input();
    return 0;
}

