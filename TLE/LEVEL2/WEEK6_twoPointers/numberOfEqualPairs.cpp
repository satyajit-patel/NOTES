#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false); cin.tie(NULL);

// ----------------------------------------------------------------------------------------------------

// link:- https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C

void input() {
    int ans = 0;
    int n,m; cin>>n>>m;
    vi arr1(n);
    vi arr2(m);
    for(auto &it : arr1) cin>>it;
    for(auto &it : arr2) cin>>it;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(arr1[i] == arr2[j]) {
            int match = arr1[i];
            int count1 = 0, count2 = 0;
            while(i < n && arr1[i] == match) {
                i++;
                count1++;
            }
            while(j < m && arr2[j] == match) {
                j++;
                count2++;
            }
            ans += (count1 * count2);
        }
        else if(arr1[i] < arr2[j]) i++;
        else j++;
    }
    cout<<ans<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // IOS
    input();
    return 0;
}

