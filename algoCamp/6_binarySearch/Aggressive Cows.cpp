// https://practice.geeksforgeeks.org/problems/aggressive-cows/1
class Solution {
public:
    bool f(int M, int n, int k, std::vector<int>& stalls) {
        int numCow = 1;
        int lastCowStall = stalls[0];
        for(int i=1; i<n; i++) {
            if(stalls[i]-lastCowStall >= M) {
                numCow += 1;
                lastCowStall = stalls[i];
            }
            if(numCow >= k) return true;
        }
        return false;
    }
    
    int solve(int n, int k, vector<int>& stalls) {
        std::sort(stalls.begin(), stalls.end());
        int L = -1, H = stalls[n-1] + 1;
        while(H-L >= 2) {
            int M = (L+H)/2;
            f(M, n, k, stalls) ? L = M : H = M;
        }
        return L;
    }
};
