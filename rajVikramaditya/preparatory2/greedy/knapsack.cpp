#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>

struct item {
	int profit; 
    int weight;	
};
bool cmp(item i1, item i2) {
	// (i1.profit/i1.weight) > (i2.profit/i2.weight) -------> equation
	return (i1.profit * i2.weight) > (i2.profit * i1.weight); 
}
double greedyKnapsack() {
	int n,w; cin>>n>>w;
	item arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i].profit>>arr[i].weight;
	}
	sort(arr, arr+n, cmp);
	double ans = 0;
	for(int i=0; i<n; i++) {
		if(w > 0 && arr[i].weight <= w) {
			ans += arr[i].profit;
			w -= arr[i].weight;
            if(w == 0) break;
		}
		else if(w > 0) {
			ans += (arr[i].profit * w * 1.0) / (arr[i].weight);
			break;
		}
	}
	return ans;
}
int main() {
	
	cout<<greedyKnapsack()<<"\n";
	return 0;
}