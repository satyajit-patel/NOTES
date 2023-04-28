#include<bits/stdc++.h>
#define int long long int
#define vi vector<int>
using namespace std;

vi prex(vi &soldier, int n) {
	vi prefix(n);
	for(int i=0; i<n; i++) {
		if(i == 0) prefix[i] = soldier[i];
		else prefix[i] = soldier[i] + prefix[i-1];
	}
	return prefix;
}
signed main() {
	int n,q; cin>>n>>q;
	vi soldier(n), enemy(q);
	for(auto &it:soldier) cin>>it;
	for(auto &it:enemy) cin>>it;
	vi prefixSol = prex(soldier, n);
	int arrow = 0;
	for(int i=0; i<q; i++) {
		arrow += enemy[i];
		int idx = upper_bound(prefixSol.begin(), prefixSol.end(), arrow) - prefixSol.begin();
		int sol = n-idx;
		if(idx == n) {
			arrow = 0;
			sol = n;
		}
		cout<<sol<<"\n";
	}
	return 0;
}