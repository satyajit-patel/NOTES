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
#define     int     long long int
#define     vi      vector<int>
#define     endl    "\n" 
void contestSolve() {
    int tc; cin>>tc;
    while(tc--) {
        
    }
}

bool go(vi &arr, int n, int mid, int cows) {
	int noOfStall = arr[0];
	int count = 1;
	for(int i=1; i<n; i++) {
		if(arr[i]-noOfStall >= mid) {
			count++;
			noOfStall = arr[i];
		}
	}
	return (count >= cows);
}
int bs(vi &arr, int n, int cows) {
	int low = 1, high = arr[n-1]-arr[0];
	int ans = -1;
	while(low <= high) {
		int mid = (low+high)/2;
		bool isThisTheOne = go(arr, n, mid, cows);
		//log(low, high, mid, isThisTheOne);
		if(isThisTheOne) {
			ans = mid;
			low = mid+1; //keep explore for more large value
		}
		else high = mid-1;
	}
	return ans;
}
void normalSolve() {
	vi arr = {1,2,4,8,9};
	int n = arr.size();
	int cows = 3;
	int ans = bs(arr, n, cows);
	cout<<ans<<"\n";
}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}
