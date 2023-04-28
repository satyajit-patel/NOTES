// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool predicate(int mid, int* arr, int N, int students) {
        int piece = 1;
        int sum = 0;
        for(int i=0; i<N; i++) {
            if(arr[i] > mid) return false;
            sum += arr[i];
            if(sum > mid) {
                piece++;
                sum = arr[i];
            }
        }
        // cout<<piece<<" "<<students<<endl;
        // <= because we are trying to allocate each student (at most) "mid" pages
        return piece <= students;
    }
    int findPages(int A[], int N, int M) {
        if(N < M) return -1;
        // std::accumulate(start, end+1, initial sum)
        int L = -1, H = std::accumulate(A, A+N, 0)+1;
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            // cout<<mid<<" ";
            // we have to minimize the maximum
            (predicate(mid, A, N, M)) ? (H = mid) : (L = mid);
        }
        return H;
    }
};