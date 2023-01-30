#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// ----------------------------------------------------------------------------------------------------

// 

void selectionSort(vector<int> arr) {
    // small element gets position first at front
    for(auto &it : arr) cout<<it<<" ";
    cout<<endl;

    int swaps = 0;
    for (int i=0; i<arr.size()-1; i++) {
        int mini = i;
        for (int j=i+1; j<arr.size(); j++) {
            if(arr[j] < arr[mini]){
                mini = j;
                swaps++;
            }
        }
        std::swap(arr[i], arr[mini]);

        for(auto &it : arr) cout<<it<<" ";
        cout<<endl;
    }
    cout<<swaps<<endl;
}

void bubbleSort(vector<int> arr) {
    // big element gets position first at back
    for(auto &it : arr) cout<<it<<" ";
    cout<<endl;

    int swaps = 0;
    for(int i=0; i<arr.size()-1; i++) {
        for (int j=0; j<arr.size()-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swaps++;
            }    
        }

        for(auto &it : arr) cout<<it<<" ";
        cout<<endl;
    }
    cout<<swaps<<endl;
}

void insertionSort(vector<int> arr) {
    // keep picking 1 card at a time and place it in it's appropriate position
    for(auto &it : arr) cout<<it<<" ";
    cout<<endl;

    int swaps = 0;
    for(int i=0; i<arr.size(); i++) {
        int j = i;
        while (j>0 && arr[j] < arr[j-1]) {
            std::swap(arr[j], arr[j-1]);
            swaps++;
            j--;
        }

        for(auto &it : arr) cout<<it<<" ";
        cout<<endl;   
    }
    cout<<swaps<<endl;
}

void input() {
    int n; cin>>n;
    vector<int> arr(n);
    for(auto &it : arr) cin>>it;
    
    selectionSort(arr);
    cout<<endl;
    bubbleSort(arr);
    cout<<endl;
    insertionSort(arr);
    cout<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

