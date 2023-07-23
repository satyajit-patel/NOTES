// https://practice.geeksforgeeks.org/problems/selection-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    int select(int arr[], int i){
        // code here such that selectionSort() sorts arr[]
    }
     
    void selectionSort(int arr[], int n) {
       for(int i=0; i<n-1; i++) {
           int mini = i;
           for(int j=i+1; j<n; j++) {
               if(arr[mini] > arr[j]) mini = j;
           }
           std::swap(arr[mini], arr[i]);
       }
    }
};