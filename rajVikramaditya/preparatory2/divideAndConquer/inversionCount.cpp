#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 

int merge(vi &arr, int low, int mid, int high) {
    int l=low, r=mid+1, cnt=0;
    vi temp;
    while(l<=mid && r<=high) {
        if(arr[l] <= arr[r]) temp.push_back(arr[l++]);
        else {
            cnt += mid-l+1;
            temp.push_back(arr[r++]);
        }
    }
    //if anythig left
    while(l<=mid) temp.push_back(arr[l++]);
    while(r<=high) temp.push_back(arr[r++]);

    int j=0;
    for(int i=low; i<=high; i++) arr[i] = temp[j++];
    return cnt;
}
int mergeSort(vi &arr, int low, int high) {
    int size = high-low+1;
    if(size == 1) return 0;

    int mid = (low+high)/2;
    int left = mergeSort(arr, low, mid);
    int right = mergeSort(arr, mid+1, high);
    int cnt = merge(arr, low, mid, high);
    return cnt+left+right;
}
int main() {
    vi arr = {1,4,5,2,3,6};
    int inversion = mergeSort(arr, 0, arr.size()-1);
    cout<<inversion<<"\n";
    for(auto &it:arr) cout<<it<<" ";
    return 0;
}