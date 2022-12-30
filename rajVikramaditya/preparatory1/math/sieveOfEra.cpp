#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long int

int N = 1e5+5;
vi sieve(N, 1);
vi prefixSieve(N, 0);
void preComputePrime() {
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i=2; i*i<=N; i++) {
        if(sieve[i] == 0) continue;
        for(int j=i*i; j<=N; j+=i) {
            sieve[j] = 0;
        }
    }
    for(int i=2; i<=N; i++) prefixSieve[i] = sieve[i] + prefixSieve[i-1];
}
void printPrime(int L, int R) {
    preComputePrime();
    for(int i=L; i<=R; i++) {
        if(sieve[i] == 1) cout<<i<<" ";
    }


    int ans = prefixSieve[R];
    if(L > 0) ans-= prefixSieve[L-1];
    cout<<"\nnumber of primes "<<ans<<"\n";
}
signed main() {
    int L=2, R=12;
    printPrime(L,R);
    return 0;
}