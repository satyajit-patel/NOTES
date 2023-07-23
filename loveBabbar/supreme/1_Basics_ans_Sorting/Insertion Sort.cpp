// https://practice.geeksforgeeks.org/problems/insertion-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include<bits/stdc++.h>
class Solution {
public:
    void insert(int arr[], int i) {
    
    }
    void insertionSort(int arr[], int n) {
        for(int i=0; i<n; i++) {
            int j = i;
            while(j>0 && arr[j-1]>arr[j]) {
                std::swap(arr[j-1], arr[j]);
                j--;
            }
        }
    }
};