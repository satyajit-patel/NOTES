#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false); cin.tie(NULL);

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1641/

void input() {
    int n,x; cin>>n>>x;
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    std::sort(arr.begin(), arr.end());
    for(int i=0; i<n-2; i++) {
        int low = i+1, high = n-1;
        while(low < high) {
            int twoSum = arr[i].first + arr[low].first + arr[high].first;
            if(twoSum < x) low++;
            else if(twoSum > x) high--;
            else {
                cout<<arr[i].second<<" "<<arr[low].second<<" "<<arr[high].second<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // IOS
    input();
    return 0;
}

