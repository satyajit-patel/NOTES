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
  //AD HOC
  // approach1
  vi arr1 = {1,4,5,9}, arr2 = {2,3,6,10};
  vi A1;
  for(auto &it : arr1) A1.push_back(it);
  for(auto &it : arr2) A1.push_back(it);
  std::sort(A1.begin(), A1.end()); // O(NLogN)
  for(auto &it : A1) std::cout<<it<<" ";
  newLine;
  // approach2
  vi A2;
  int i = 0, j = 0;
  while(i<arr1.size() && j<arr2.size()) { // O(N)
    if(arr1[i] <= arr2[j]) A2.push_back(arr1[i++]);
    else A2.push_back(arr2[j++]);
  }
  while(i < arr1.size()) A2.push_back(arr1[i++]);
  while(j < arr2.size()) A2.push_back(arr2[j++]);
  for(auto &it : A2) std::cout<<it<<" ";
  newLine;
  
  // 2sorted arr for each ele in ist arr find #ele smaller than that in 2nd arr
  // approach1
  vi A3;
  for(auto &it : arr1) { // O(N)
    int idx = std::lower_bound(arr2.begin(), arr2.end(), it) - arr2.begin();// O(LogN)
    A3.pb(idx);
  } // i.e O(NLogN)
  for(auto &it : A3) std::cout<<it<<" ";
  newLine;
  // approach2
  vi A4;
  i = 0, j = 0;
  while(i < arr1.size()) { // O(N)
    while(j<arr2.size() && arr1[i]<arr2[j]) j++;
    A4.pb(j);
    i++;
  }
  for(auto &it : A3) std::cout<<it<<" ";
  newLine;





  
  // GOOD SEGMENT (all these can be done using binarySearch either)
  // good segment using binary search -> O(NLogN)
  // good segment using two pointers -> O(N)
  // find the length of longest subarray which sum is <= K

  vi arr = {1,2,1,2,3,1,2,2,3,4};
  int k = 7;
  /*
  trick :-
    start from each index go left side till it is a good segment ans store the size
    i.e
    for index 0 --------> size = 1 --->[1] as it is <= k
    for index 1 --------> size = 2 --->[1,2] as it is <= k
    for index 2 --------> size = 3 --->[1,2,1] as it is <= k
    for index 3 --------> size = 4 --->[1,2,1,2] as it is <= k
    for index 4 --------> size = 3 --->[1,2,3] as it is <= k
    for index 5 --------> size = 4 --->[1,2,3,1] as it is <= k
    for index 6 --------> size = 3 --->[3,1,2] as it is <= k
    for index 7 --------> size = 3 --->[1,2,2] as it is <= k
    for index 8 --------> size = 3 --->[2,2,3] as it is <= k
    for index 9 --------> size = 2 --->[3,4] as it is <= k

    after that the max size of all of these will be my answer
  */
  int ans = 0, sum = 0;
  i = 0, j = 0;
  while(j<arr.size()) {
    sum += arr[j];
    while(i<=j && sum>k) {
      sum -= arr[i];
      i++;
    }
    ans = std::max(ans, j-i+1);
    j++;
  }
  std::cout<<ans<<endl;
  /*
    j is moving forward so O(N)
    i is moving forward so O(N)
    i.e O(N) + O(N) = O(2N) = O(N)
  */


  // find the length of longest subarray with not more than "K" distinct elements 
  k = 3;
  ans = 0;
  i = 0, j = 0;
  std::map<int, int> freq;
  while(j<arr.size()) {
    freq[arr[j]]++;
    while(i<=j && freq.size()>k) {
      freq[arr[i]]--;
      if(freq[arr[i]] == 0) freq.erase(arr[i]);
      i++;
    }
    ans = std::max(ans, j-i+1);
    j++;
  }
  std::cout<<ans<<endl;


  // find the length of smallest subarray which sum is >= K
  k = 7;
  ans = INT_MAX, sum = 0;
  i = 0, j = 0;
  while(j<arr.size()) {
    sum += arr[j];
    while(i<=j && sum>=k) {
      ans = std::min(ans, j-i+1);
      sum -= arr[i];
      i++;
    }
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
