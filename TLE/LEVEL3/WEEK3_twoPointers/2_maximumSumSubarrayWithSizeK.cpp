#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define newLine std::cout<<"\n";
#define int long long int
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define pb push_back
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link :- 

void input() {
  // find the max sum subarray with window size "K"
  int K = 3;
  vi arr = {1,2,3,2,1,1,4,5};

  // sliding window concept
  int ans = 0, sum = 0;
  int i = 0, j = 0;
  while(j<arr.size()) {
    // calculation
    sum += arr[j];
    if(j-i+1 < K) {
      j++;
      continue;
    }

    // update and slide
    ans = std::max(ans, sum);
    sum -= arr[i];
    i++;
    j++;
  }
  std::cout<<ans<<endl;
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
