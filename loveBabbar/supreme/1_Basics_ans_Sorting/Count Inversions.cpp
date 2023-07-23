// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    long long inversion;
    void merge(std::vector<long long>&arr, int L, int mid, int H) {
        int n1 = mid-L+1;
        int n2 = H-mid;
        std::vector<long long> A(n1), B(n2);
        for(int i=0; i<n1; i++) A[i] = arr[L+i];
        for(int i=0; i<n2; i++) B[i] = arr[(mid+1)+i];
        int i = 0, j = 0;
        while(i<n1 && j<n2) {
            if(A[i] <= B[j]) arr[L++] = A[i++];
            else {
                inversion += A.size()-i;
                arr[L++] = B[j++];
            }
        }
        while(i < n1) arr[L++] = A[i++];
        while(j < n2) arr[L++] = B[j++];
    }
    
    void merge_sort(std::vector<long long>& arr, int L, int H) {
        if(L < H) {
            int mid = (L + H)/2; 
            merge_sort(arr, L, mid);
            merge_sort(arr, mid+1, H);
            merge(arr, L, mid, H);
        }
    }

    long long int inversionCount(long long arr[], long long N) {
        inversion = 0;
        std::vector<long long> A;
        for(long long i=0; i<N; i++) A.push_back(arr[i]);
        merge_sort(A, 0, A.size()-1);
        return inversion;
    }
};