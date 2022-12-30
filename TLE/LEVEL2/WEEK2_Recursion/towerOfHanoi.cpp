#include<bits/stdc++.h>
using namespace std;


#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}




#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     endl    "\n" 
#define     int     long long int
#define     vi      vector<int>
#define     vvi     vector<vector<int>>
#define     vvc     vector<vector<char>>
#define     vpi     vector<pair<int, int>>
#define     M       (int)1e9+7

//---------------------------------------------------------------------


// https://cses.fi/problemset/task/2165
void f(int n, int stack1, int stack2, int stack3, vpi& ans) {
    // base case
    if(n == 0) return;
    
    // ist we take the all elements from stack1 to stack2 using stack3
    f(n-1, stack1, stack3, stack2, ans);
    ans.push_back({stack1, stack3});
    // then stack2 to stack3 using stack1
    f(n-1, stack2, stack1, stack3, ans);
}
void input() {
    int n; cin>>n;
    vpi ans;
    // goal is to move all the disks to the right stack using the middle stack
    f(n, 1, 2, 3, ans);
    int moves = (1 << n) - 1;
    cout<<moves<<endl;
    for(auto &it : ans) cout<<it.first<<" "<<it.second<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

