#include<iostream>
#include<vector>

using namespace std;
int main()
{
    cout<<"enter\n";
    int n; cin>>n;
    int arr[n];
    vector<int> prefix(n);
    vector<int> prefix1(n);
    for(auto &it :arr) cin>>it;
    cout<<"enter range\n";
    int l, r; cin>>l>>r;
    
    for(int i=0; i<n; ++i){
        if(i == 0){
            prefix[0] = arr[0];
        }
        else{
            prefix[i] = arr[i] + prefix[i-1];
        }
    }
    for(int i=0; i<n; ++i){
        if(i == 0){
            prefix1[0] = arr[0];
        }
        else{
            prefix1[i] = arr[i] * prefix1[i-1];
        }
    }

    cout<<"\n";
    for(auto it : arr) cout<<it<<" ";
    cout<<"\n";
    for(auto it : prefix) cout<<it<<" ";
    int sum = prefix[r];
    if(l > 0)
        sum -= prefix[l-1];
    int prd = prefix1[r];
    if(l > 0)
        prd /= prefix1[l-1];
    cout<<"\nsum is : "<<sum<<"\nproduct is : "<<prd;
    return 0;
}