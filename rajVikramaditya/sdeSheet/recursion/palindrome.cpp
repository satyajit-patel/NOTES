#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

//tc->O(N/2), sc->O(N/2)
bool isPalindrome(int i, string s, int n) {
   if(i >= n/2) return true;
   if(s[i] == s[n-i-1]) return isPalindrome(i+1, s, n);
   return false;
}
int main() {
    string s; cin>>s;
    bool flag = isPalindrome(0, s, s.size());
    if(flag) cout<<"yes";
    else cout<<"nope";
    return 0;
}