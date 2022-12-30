#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> prex(vector<vector<int>> &arr, int n, int m) {
	vector<vector<int>> prefix(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			prefix[i][j] = arr[i][j];
			if(i > 0) prefix[i][j] += prefix[i-1][j];
			if(j > 0) prefix[i][j] += prefix[i][j-1];
			if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<prefix[i][j]<<" ";
		}
		cout<<"\n";
	}
	return prefix;
}
int main() {
	int n=4, m=4;
	vector<vector<int>> arr(n, vector<int>(m, 5));		//5	5 5 5
	vector<vector<int>> prefix = prex(arr,n,m);			//5 5 5 5
	//find sum from x1,y1 to x2,y2						//5 5 5 5
	int x1=2,y1=1, x2=3,y2=2;							//5 5 5 5
	int sum = prefix[x2][y2];
	if(x1 > 0) sum -= prefix[x1-1][y2];
	if(y1 > 0) sum -= prefix[x2][y1-1];
	if(x1>0 && y1>0) sum += prefix[x1-1][y1-1];
	cout<<sum<<"\n";   
	return 0;
}