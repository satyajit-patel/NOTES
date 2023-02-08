#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false); cin.tie(NULL);

// ----------------------------------------------------------------------------------------------------

// link:- https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D

void input() {
   int ans = 0;
   int n,s; cin>>n>>s;
   vi arr(n);
   for(auto &it : arr) cin>>it;
   int i = 0, j = 0, sum = 0;
   while(i<n && j<n) {
        sum += arr[j];
        while(i <= j && sum >= s) {
            sum -= arr[i];
            i++;
        }
        int size = j-i+1;
        ans += size;
        j++;
   }
   int total  = (n * (n+1)) / 2;
   int newAns = total - ans; 
   cout<<newAns<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

