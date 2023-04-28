#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>

struct item {
    int id;
    int deadline;	
	int profit; 
};
bool cmp(item i1, item i2) {
	return i1.profit > i2.profit; 
}
struct ans {
    int job = 0;
    int pro = 0; 
};
void greedyJobsequence(ans &a) {
	int n; cin>>n;
	item arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
	}
	sort(arr, arr+n, cmp);
    int x; cin>>x;
    set<int> s;
    for(int i=0; i<n; i++) {
        s.insert(i);
    }
	for(int i=0; i<n; i++) {
		int d = arr[i].deadline;
        int p = arr[i].profit;
        auto it = s.lower_bound(d);
        if(it != s.begin()) {
            it--;
            a.pro += p;
            a.job += 1;
            s.erase(it);
        }
	}
}
int main() {
	 ans a;
	greedyJobsequence(a);
    cout<<a.job<<" "<<a.pro<<"\n";
	return 0;
}