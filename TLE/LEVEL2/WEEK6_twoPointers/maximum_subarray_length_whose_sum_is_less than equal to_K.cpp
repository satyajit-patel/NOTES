#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums, int k) {
  int sum = 0;
  int ans = 0;
  int i = 0, j = 0;
  while (j < nums.size()) {
    sum += nums[j];

    while (i <= j && sum > k) {
      sum -= nums[i];
      i++;
    }

    if (sum <= k) {
      ans = std::max(ans, j - i + 1);
    }
    j++;
  }
  return ans;
}

void input() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &it : nums)
    cin >> it;
  int k;
  cin >> k;
  cout << f(nums, k) << endl;
}

// --------------------------------------------
signed main() {
  input();
  return 0;
}
