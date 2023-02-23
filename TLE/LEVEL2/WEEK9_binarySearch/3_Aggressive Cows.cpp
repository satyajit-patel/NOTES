// https://practice.geeksforgeeks.org/problems/aggressive-cows/1
class Solution {
public:
    bool predicate(int M, const vector<int>& stalls, int n, int k) {
        int cows = 1;
        int prevStall = stalls[0];
        for(int i=1; i<n; i++) {
            if(stalls[i] - prevStall >= M) {
                prevStall = stalls[i];
                cows++;
            }
        }
        return cows >= k;
    }
    int solve(int n, int k, vector<int> &stalls) {
        std::sort(stalls.begin(), stalls.end());
        int L = 0, H = 1e9+1;
        while(H-L > 1) {
            int M = L + (H-L)/2;
            (predicate(M, stalls, n, k)) ? (L = M) : (H = M);
        }
        return L;
    }
};