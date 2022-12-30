#include<bits/stdc++.h>
using namespace std;

void go(vector<int> &arr, int n) {
    
    int i=0, j=0, sum=0, length=0, lastSum=INT_MIN, maxi=0;
    /*
    vector<int> ans;
    while(j<n) {
        ans.push_back(arr[j]);
        sum += arr[j];
        if(sum < 0) {
            sum = 0;
            i = ++j;
            length = 0; 
        }
        else if(sum > lastSum) {
            length = max(length, j-i+1);
            maxi = sum;
            for(auto &it:ans) cout<<it<<" ";
            cout<<endl;
        }
        lastSum=sum;
        j++;
    }*/



    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
            cout<<arr[i]<<" ";
        }
        if(sum < 0) sum=0;        
    }





    //return {length, maxi};
}
int main() {
    vector<int> arr = {10,10,10,-2,-2};
    go(arr, arr.size());
    //cout<<it.first<<" "<<it.second;
    return 0;
}