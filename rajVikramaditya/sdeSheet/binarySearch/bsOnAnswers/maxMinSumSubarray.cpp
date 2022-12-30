bool blackBox(int mid, vi &nums, int m) {
    int split = 0, sum = 0;
    for(auto &it : nums) {
        sum += it;
        if(sum > mid) {
            split++;
            sum = 0;
        }
    }
    return split >= m;
}
void normalSolve() {
    // leetcode 1231 divide chocolate
    int n,m; cin>>n>>m;
    vi nums(n);
    for(auto &it : nums) cin>>it;
    int low = *min_element(nums.begin(), nums.end());
    int high = 0, ans = -1;
    for(auto &it : nums) high += it;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(blackBox(mid, nums, m)) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans;
}