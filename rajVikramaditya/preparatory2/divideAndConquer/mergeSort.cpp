#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

void merge(vi &arr, int low, int mid, int high) {
    int l=low, r=mid+1;
    vi temp;
    while(l <=mid && r <= high) {
        if(arr[l] <= arr[r]) temp.push_back(arr[l++]);
        else temp.push_back(arr[r++]);
    }
    //if anythig left
    while(l<=mid) temp.push_back(arr[l++]);
    while(r<=high) temp.push_back(arr[r++]);

    int j=0;
    for(int i=low; i<= high; i++) arr[i] = temp[j++];
}
void mergeSort(vi &arr, int low, int high) {
    int size = high-low+1;
    if(size == 1) return;

    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
int main() {
    vector<int> arr = {5,4,3,1,2,10};
    int n = arr.size();
    mergeSort(arr,0,n-1);
    for(auto &it:arr) cout<<it<<" ";
    return 0;
}