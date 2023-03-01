// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool predicate(int mid, int* A, int N, int student) {
        int child = 1;
        int pages = 0;
        for(int i=0; i<N; i++) {
            if(A[i] > mid) return false;
            pages += A[i];
            if(pages > mid) {
                child += 1;
                pages = A[i];
            }
        }
        return child <= student;
    }

    int findPages(int A[], int N, int M) {
        if(N < M) return -1;
        int L = -1, H = 1e9+1;
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            (predicate(mid, A, N, M)) ? (H = mid) : (L = mid);
        }
        return H;
    }
};