bool blackBox(int mid, vi &nums, int m) {
    int split = 1, sum = 0;
    for(auto &it : nums) {
        sum += it;
        if(sum > mid) {
            split++;
            sum = 0;
            sum += it;
        }
    }
    return split <= m;
}
void normalSolve() {
    // leetcode 410 split array largest sum
    int n,m; cin>>n>>m;
    vi nums(n);
    for(auto &it : nums) cin>>it;
    int low = *max_element(nums.begin(), nums.end());
    int high = 0, ans = -1;
    for(auto &it : nums) high += it;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(blackBox(mid, nums, m)) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<ans;
}