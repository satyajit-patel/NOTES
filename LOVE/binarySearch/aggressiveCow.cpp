//https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=1
bool check(int mid, vector<int>& stalls, int k) {
    int cow = 1;
    int lastPos = stalls[0];
    for(int i=0; i<stalls.size(); i++) {
        if(stalls[i]-lastPos >= mid) {
            cow++;
            if(cow == k) return true;
            lastPos = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int>& stalls, int k) {
    if(stalls.size() < k) return -1;
    int ans = -1;
    int total = 0;
    for(auto &it : stalls) total += it;
    //searchSpace
    int low = 0;
    int high = total;
    std::sort(stalls.begin(), stalls.end());
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(check(mid, stalls, k)) {
            ans = mid;
            //we need as max as possible
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}