// https://practice.geeksforgeeks.org/problems/sum-equals-to-sum4006/1
class Solution {
 public:
    int findPairs(long long a[], long long n) {
        std::unordered_map<long long, long long> mpp;
        for(long long i=0; i<n-1; i++) {
            for(long long j=i+1; j<n; j++) {
                long long sum = a[i] + a[j];
                mpp[sum]++;
                if(mpp[sum] >= 2) return 1;
            }
        }
        return 0;
    }
};