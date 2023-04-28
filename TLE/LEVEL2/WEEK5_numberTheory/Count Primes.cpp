// https://leetcode.com/problems/count-primes/description/
class Solution {
public:
    int countPrimes(int n) {
        std::vector<int> prime(n, 1);
        for(int i=2; i<n; i++) {
            if(prime[i]) for(int j=i+i; j<n; j+=i) prime[j] = 0;
        }

        int count = 0;
        for(int i=2; i<n; i++) if(prime[i] == 1) count += 1;
        return count;
    }
    
    int countPrimes(int n) {
        if(n < 2) return 0;

        std::vector<int> prime(n, 1);
        prime[0] = 0;
        prime[1] = 0;
        for(int i=0; i<n; i++) {
            if(prime[i]) for(int j=i+i; j<n; j+=i) prime[j] = 0;
        }

        std::vector<int> prefix(n, 0);
        prefix[0] = prime[0];
        for(int i=1; i<n; i++) prefix[i] = prime[i] + prefix[i-1];
        
        return prefix[n-1];
    }

};