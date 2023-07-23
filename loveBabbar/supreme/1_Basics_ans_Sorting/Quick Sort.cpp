// https://practice.geeksforgeeks.org/problems/quick-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    int partition (int arr[], int left, int right) {
       int pivot = left;
       while(left < right) {
           while(arr[left] <= arr[pivot]) left++;
           while(arr[right] > arr[pivot]) right--;
           if(left < right) std::swap(arr[left], arr[right]);
       }
       std::swap(arr[pivot], arr[right]);
       return right;
    }
    
    void quickSort(int arr[], int left, int right) {
        // base case
        if(left >= right) return;
        
        // 1 case pre work
        int pivot = partition(arr, left, right);
        
        // recursive case
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
};