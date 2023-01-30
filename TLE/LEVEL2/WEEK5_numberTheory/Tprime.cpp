#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define M       1e7

// ----------------------------------------------------------------------------------------------------

// https://codeforces.com/problemset/problem/230/B

std::set<int> Tprime;
std::vector<int> sieve(M, 1);
void computePrime() {
    for(int i=2; i<M; i++) {
        if(sieve[i]) {
	    // just store the square of every prime num.. it's a modified version of sieve
            Tprime.insert(i  * i);
            for(int j=i*i; j<M; j+=i) sieve[j] = 0;
        }
    }
}
void input() {
    int n; cin>>n;
    computePrime();
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        if(Tprime.count(x)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

