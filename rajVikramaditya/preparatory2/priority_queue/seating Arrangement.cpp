
//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/seating-arrangement-6b8562ad/
#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool isEvenLength(string s, int totalLength, int i) {
	return (s[i-1] == 'R' && totalLength%2 == 0);
}
signed main() {
	int n,p; cin>>n>>p;
	string s; cin>>s;

	map<int, int> m;
	priority_queue<pair<int, int>> pq;
	pq.push({n, -1});
	for(int person=1; person<=p; person++) {
		int totalLength = pq.top().first;
		int firstIndex = pq.top().second * -1;
		int lastIndex = firstIndex + totalLength - 1;
		int mid = (firstIndex+lastIndex)/2;

		if(isEvenLength(s, totalLength, person) == true) mid += 1;
		m[mid] = person;
        
		if(firstIndex != mid) pq.push({mid-firstIndex, firstIndex*-1});
		if(mid != lastIndex) pq.push({lastIndex-mid, (mid+1)*-1});
        pq.pop();
	}
	int q; cin>>q;
	while(q--) {
		int x; cin>>x;
		if(m.find(x) != m.end()) cout<<m[x]<<"\n";
		else cout<<-1<<"\n";
	}
	return 0;
}