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
};