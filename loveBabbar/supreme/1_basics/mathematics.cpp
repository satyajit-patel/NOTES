#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      std::vector<int>
#define vvi     std::vector<std::vector<int>>
#define ADJ     std::unordered_map<int, std::unordered_set<int>>
const int MOD = 1e9 + 7;

namespace math {
    int mul(int a, int b) {
        return ((a%MOD) * (b%MOD))%MOD;
    }

    int add(int a, int b) {
        return ((a%MOD) + (b%MOD))%MOD;
    }   

    int sub(int a, int b) {
        return ((a%MOD) - (b%MOD) + MOD)%MOD;
    }

    int my_pow(int base, int power) {
        int ans = 1;
        while(power) {
            if(power&1) ans = math::mul(ans, base);
            base = math::mul(base, base);
            power >>= 1;
        }
        return ans;
    }

    int div(int a, int b) {
        a %= MOD;
        int inv_b = math::my_pow(b, MOD-2);
        return a * inv_b % MOD;
    }   

    int my_gcd(int maxi, int mini) {
        return mini ? my_gcd(mini, maxi%mini) : maxi;
    }

    int lcm(int a, int b) {
        int x = mul(a, b);
        int y = math::my_gcd(a, b);
        return math::div(x, y);
    }
    vi sievePrime(int n) {
        vi prime(n, 1);
        prime[0] = 0;
        prime[1] = 0;
        for(int i=2; i*i<n; i++) {
            if(prime[i] == 0) continue;
            for(int j=i*i; j<n; j+=i) prime[j] = 0;
        }
        return prime;
    }

    vi my_fact(int n) {
        vi fact(n+1);
        fact[0] = 1;
        for(int i=1; i<=n; i++) fact[i] = math::mul(i, fact[i-1]);
        return fact;
    }

    int nCr(int n, int r) {
        if(r > n) return 0;
        if(n < 0) return 0;
        if(r < 0) return 0;
        if(n == r) return 1;

        vi fact = math::my_fact(n+1);
        int numo = fact[n];
        int deno = math::mul(fact[r], fact[n-r]);
        return math::div(numo, deno);
    }
}

namespace my {

}

// ----------------------------------------------------------------------------------------------------

// link:- 

void input() {
    
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}