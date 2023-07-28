// https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    vector<int> sievePrime(int N) {
        vector<int> prime(N+1, 1);
        prime[0] = 0, prime[1] = 0;
        for(int i=2; i*i<=N; i++) {
            if(prime[i] == 0) continue;
            for(int j=i*i; j<=N; j+=i) prime[j] = 0;
        }
        return prime;
    }

    vector<int> sieveOfEratosthenes(int N) {
        vector<int> ans;
        vector<int> prime = sievePrime(N);
        for(int i=0; i<=N; i++) if(prime[i] == 1) ans.push_back(i);
        return ans;
    }
};