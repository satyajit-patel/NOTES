// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool predicate(int mid, int* A, int books, int students) {
        int studentCount = 1;
        int pageCount = 0;
        for(int i=0; i<books; i++) {
            int curPageCount = A[i];
            if(curPageCount > mid) return false;
            pageCount += curPageCount;
            if(pageCount > mid) {
                studentCount++;
                pageCount = curPageCount;
            }
        }
        return studentCount <= students;
    }

    int findPages(int A[], int N, int M) {
        int books = N;
        int students = M;
        if(books < students) return -1;
        int left = -1;
        int total = 0;
        for(int i=0; i<books; i++) total += A[i];
        int right = total+1;
        while(right-left >= 2) {
            int mid = (left+right)/2;
            (predicate(mid, A, books, students))?(right = mid):(left = mid);
        }
        return right;
    }
};