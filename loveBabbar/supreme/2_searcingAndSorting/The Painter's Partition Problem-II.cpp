// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
class Solution {
public:
    bool predicate(int mid, int* arr, int N, int students) {
        int piece = 1;
        long long int sum = 0;
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
    
    long long int findPages(int A[], int N, int M) {
        // if(N < M) return -1;
        long long int sum = 0;
        for(int i=0; i<N; i++) sum += A[i];
        long long int L = -1, H = sum+1;
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            // cout<<mid<<" ";
            // we have to minimize the maximum
            (predicate(mid, A, N, M)) ? (H = mid) : (L = mid);
        }
        return H;
    }
    long long minTime(int arr[], int n, int k) {
        return findPages(arr, n, k);
    }
};