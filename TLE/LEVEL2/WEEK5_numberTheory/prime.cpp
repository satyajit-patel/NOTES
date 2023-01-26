#include<set>
#include<map>
#include<deque>
#include<vector>
#include<string>  //contains string class ans standard stoi() etc
#include<sstream> //standard stringstream() etc
#include<utility> //contains pair class
#include<iostream>
#include<algorithm>

#define endl    "\n"
#define int     long long int

//---------------------------------------------------->

namespace my {

    // factors always appears in pair
    // i.e a = i then b = n/i
    // le n = 10................ a * b = n so... b = n/a
    /*
            a         b
        --------   --------
        1           10
        2           5
        4           2
        10          1

    */

   bool isPrime_bForceMethod(int n) { // O(N)
        if(n <= 1) return false;
        // prime = only 2 factor 1 and he himself
        for(int i=2; i<n; i++) {
            if(n % i == 0) return false;
        }
        return true;
   }


   bool isPrime_sRootMethod(int n) { // O(rootN)
        if(n <= 1) return false;
        for(int i=2; i*i<=n; i++) {
            if(n % i == 0) return false;
        }
        return true;
   }

   // sieve of eratosthenes-----------> O(NloglogN)
}

//---------------------------------------------------->

void input() {
    int tc; std::cin>>tc;
    while(tc--) {
        int n; std::cin>>n;
        
        // if(my::isPrime_bForceMethod(n)) std::cout<<"prime\n";
        // else std::cout<<"not prime\n";

        if(my::isPrime_sRootMethod(n)) std::cout<<"prime\n";
        else std::cout<<"not prime\n";
    }
}

//----------------------------------------------------->

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    input();
    return 0;
}