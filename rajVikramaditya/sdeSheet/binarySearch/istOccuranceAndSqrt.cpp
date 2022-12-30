#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

int M = int(1e9+7);
int myPow(int base, int power) {
    int ans = 1;
    while(power) {
        if(power%2) {
            power -= 1;
            ans = (base * ans) % M;
        }
        else {
            power /= 2;
            base = (base * base) % M;
        }
    }
    return ans;
}
int findSquareRoot(int n) {
    int low = 0, high = n, ans = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(mid*mid <= n) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int BS2(int x, vi &arr) {
    int low = 0, high = arr.size()-1, ans = -1;
    while(low <= high) {
        int mid = (low + high) /2;
        if(arr[mid] <= x) {
            ans = mid;
            low = mid +1;
        }
        else high = mid-1;
    }
    return ans;
}
int BS(int x, vi &arr) {
    int low = 0, high = arr.size()-1, ans = -1;
    while(low <= high) {
        int mid = (low + high) /2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid+1;
    }
    return ans;
}
int main() {
    int n,x; cin>>n>>x;
    vi arr(n); 
    for(auto &it : arr) cin>>it; 
    sort(arr.begin(), arr.end());
    if(binary_search(arr.begin(), arr.end(), x)) {
        
        int firstId = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int lastId = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int ans = (lastId - 1) - firstId + 1;
        cout<<"numOfOcuurance = "<<ans<<endl;
        
        int firstOccurance = BS(x, arr);
        int lastOccurance = BS2(x, arr);
        cout<<"1st occurance is at index "<<firstOccurance<<endl;
        cout<<"last occurance is at index "<<lastOccurance<<endl;
        int res = lastOccurance - firstOccurance + 1;
        cout<<"numOfOcuurance = "<<res<<endl;
        
    }
    else cout<<"doesn't exist\n";
    
    cout<<findSquareRoot(n)<<endl;//O(logN)
    cout<<int(sqrt(n))<<endl;//O(rootN) and it's default return type is double
    
    cout<<myPow(2, n)<<endl;//O(logN)
    cout<<pow(2, n)<<endl;//O(N);
    return 0;
}
