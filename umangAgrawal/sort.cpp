#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link:- 

void bubbleSort(vector<int> arr) {
  // big element gets position first at back
  int swaps = 0;
  int compa = 0;
  for(int i=0; i<arr.size()-1; i++) {
    for (int j=0; j<arr.size()-i-1; j++) {
        compa++;
        if(arr[j] > arr[j+1]) {
            std::swap(arr[j], arr[j+1]);
            swaps++;
        }    
    }
  }
  for(auto &it : arr) cout<<it<<" ";
  cout<<"\nbubble #swaps->"<<swaps<<" #compa->"<<compa<<"\n\n";
}

void insertionSort(vector<int> arr) {
  // 1 card at a time at it's appropriate position
  int swaps = 0;
  int compa = 0;
  for(int i=0; i<arr.size(); i++) {
    int j = i;
    compa++;
    while (j>0 && arr[j] < arr[j-1]) {
        std::swap(arr[j], arr[j-1]);
        swaps++;
        j--;
    } 
  }
  for(auto &it : arr) cout<<it<<" ";
  cout<<"\ninsertion #swaps->"<<swaps<<" #compa->"<<compa<<"\n\n";
}

void selectionSort(vector<int> arr) {
  // small element gets position first at front
  int swaps = 0;
  int compa = 0;
  for (int i=0; i<arr.size()-1; i++) {
    int mini = i;
    for (int j=i+1; j<arr.size(); j++) {
      compa++;
        if(arr[j] < arr[mini]){
            mini = j;
            swaps++;
        }
    }
    std::swap(arr[i], arr[mini]);
  }
  for(auto &it : arr) cout<<it<<" ";
  cout<<"\nselection #swaps->"<<swaps<<" #compa->"<<compa<<"\n\n";
}

int partition(vector<int>& arr, int L, int H) {
  int pivot = arr[L], i = L, j = H;
  while(i < j) {
    while(arr[i]<=pivot && i<H) i++;
    while(arr[j]>pivot && j>L) j--;
    if(i < j) std::swap(arr[i], arr[j]);
  }
  std::swap(arr[L], arr[j]);
  return j;
}

void quick_sort(vector<int>& arr, int L, int H) {
    if(L < H) {
        int pivotsPosition = partition(arr, L, H);
        quick_sort(arr, L, pivotsPosition-1);
        quick_sort(arr, pivotsPosition+1, H);
    }
}

void merge(vector<int>&arr, int L, int mid, int H) {
  int n1 = mid-L+1;
  int n2 = H-mid;
  vector<int> arr1(n1), arr2(n2);

  for(int i=0; i<n1; i++) arr1[i] = arr[L+i];
  for(int i=0; i<n2; i++) arr2[i] = arr[(mid+1)+i];
  int i = 0, j = 0;
  while(i<n1 && j<n2) {
    if(arr1[i] <= arr2[j]) arr[L++] = arr1[i++];
    else arr[L++] = arr2[j++];
  }
  while(i < n1) arr[L++] = arr1[i++];
  while(j < n2) arr[L++] = arr2[j++];
}

void merge_sort(vector<int>& arr, int L, int H) {
    if(L < H) {
        int mid = (L + H)/2; 
        merge_sort(arr, L, mid);
        merge_sort(arr, mid+1, H);
        merge(arr, L, mid, H);
    }
}

void input() {
  vector<int> arr = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};
  bubbleSort(arr);
  insertionSort(arr);
  selectionSort(arr);
  // quick_sort(arr, 0, arr.size()-1);
  // for(auto &it : arr) cout<<it<<" ";
  merge_sort(arr, 0, arr.size()-1);
  for(auto &it : arr) cout<<it<<" ";
}

// ---------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}
