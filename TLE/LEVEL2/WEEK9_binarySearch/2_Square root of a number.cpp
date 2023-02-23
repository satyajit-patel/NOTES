// https://practice.geeksforgeeks.org/problems/square-root/1
class Solution {
public:
    bool predicate(long long int i, long long int x) {
        return i*i <= x;
    }
    long long int floorSqrt(long long int x) {
        // binary search on solution
        // just check(predicate) the solution that.. it is valid or not
        // adjust the search space according to that
	// here L is last true and H is first false in monotonic graph
        long long int L = -1; // excluded
	long long int H = x+1; // excluded
        while(H-L > 1) {
            long long int M = L + (H-L)/2;
            (predicate(M, x)) ? L = M : H = M;
        }
        return L;
    }
};