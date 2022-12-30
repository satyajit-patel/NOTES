#include<bits/stdc++.h>
using namespace std;
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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
#define		vvi		vector<vector<int>>
void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

//---------------------------------------------------------------------






bool blackBox(int barrier, vi &nums, int cows) {
    int split = 1, lastPlaced = nums[0];
    for(auto &it : nums) {
        if(it - lastPlaced >= barrier) {
            split++;
            lastPlaced = it;
        }
    }
    return split >= cows;
}
//https://www.spoj.com/problems/AGGRCOW/
int aggresiveCows(vi &nums, int cows) {
    //logic is to tke ---> max(minSum)
    sort(nums.begin(), nums.end());
    //at worst case
    int low = 1, high = nums[nums.size()-1] - nums[0];
    int ans = -1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(blackBox(mid, nums, cows)) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}
void input() {
    int tc; cin>>tc;
    while(tc--) {



        int n,m; cin>>n>>m;
        vi nums(n);
        for(auto &it : nums) cin>>it;
        //------------------------------------
        cout<<aggresiveCows(nums, m)<<endl;
    


    }
}










//------------------------------------------------------------------------
signed main() {
    IOS
    init_code();
    input();
    return 0;
}