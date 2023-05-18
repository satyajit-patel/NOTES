// https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    void merge(int arr[], int l, int m, int r) {
         int n1 = m-l+1;
         int n2 = r-m;
         int A1[n1], A2[n2];
         for(int i=0; i<n1; i++) A1[i] = arr[i+l];
         for(int i=0; i<n2; i++) A2[i] = arr[(m+1)+i];
         int i = 0, j = 0;
         while(i<n1 && j<n2) {
             if(A1[i] <= A2[j]) arr[l++] = A1[i++];
             else arr[l++] = A2[j++];
         }
         while(i<n1) arr[l++] = A1[i++];
         while(j<n2) arr[l++] = A2[j++];
    }
    
    void mergeSort(int arr[], int l, int r) {
        // base case 
        if(l >= r) return;
        
        // 1 case pre work
        int mid = (l+r)/2;
        
        // recursive case
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};