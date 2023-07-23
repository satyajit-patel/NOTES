// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
class _Solution {
public:
    bool predicate(int _M, int* A, int N, int M) {
        int numPages = 0;
        int numStudents = 1;
        for(int i=0; i<N; i++) {
            if(A[i] > _M) return false;
            numPages += A[i];
            if(numPages > _M) {
                numPages = A[i];
                numStudents += 1;
            }
        }
        return numStudents <= M;
    }

    long long findPages(int A[], int N, int M) {
        // if(N < M) return -1; // we dont't have to return -1 here
        long long L = -1, S = 0, H = 0;
        for(int i=0; i<N; i++) S += A[i];
        H = S + 1;
        while(H-L >= 2) {
            int _M = (L + H) / 2;
            predicate(_M, A, N, M) ? H = _M : L = _M;
        }
        return H;
    }
};

class Solution {
public:
    long long minTime(int arr[], int n, int k) {
        _Solution* bookAllocation = new _Solution();
        return bookAllocation->findPages(arr, n, k);
    }
};