#include<bits/stdc++.h>
using namespace std;

int fast_expo(int a, int n) {
	if (!n) return 1;
	int p = fast_expo(a, n/2);
	return (n&1) ? (p*p*a) : (p*p);
}

int selectionSort(vector<int> arr) {
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
    return swaps;
}

int bubbleSort(vector<int> arr) {
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
    return swaps;
}

int insertionSort(vector<int> arr) {
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
    return swaps;
}

void input() {
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    cout<<selectionSort(arr)<<"\n";
    cout<<bubbleSort(arr)<<"\n";
    cout<<insertionSort(arr)<<"\n";
}

int main() {
	input();
	return 0;
}