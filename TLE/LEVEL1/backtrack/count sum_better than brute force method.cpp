// link => count all combinations of sum which are <= K
#include<bits/stdc++.h>

int f(int i, int K, std::vector<int>& arr, int sum) {
    // base case
    if(sum > K) return 0; // this conditon on top avoids many calls and helps to optimize the coce
    if(i >= arr.size()) return 1;
    
    // recursive case
    int incl = f(i+1, K, arr, sum+arr[i]);
    int excl = f(i+1, K, arr, sum);
    int ans = incl + excl;
    
    // return case
    return ans;
}

void input() {
  int N, K; std::cin>>N>>K;
  std::vector<int> arr(N);
  for(auto &it : arr) std::cin>>it;
  std::cout<<f(0, K, arr, 0)<<"\n";
}

int main() {
	input();
	return 0;
}
