//https://www.interviewbit.com/problems/allocate-books/
bool blackBox(int barrier, vector<int> &A, int students) {
    int split = 1, sum = 0;
    for(auto &it : A) {
        if(it > barrier) return false;
        if(sum + it > barrier) {
            split++;
            sum = it;
        }
        else sum += it;
    }
    return split <= students;
}
int Solution::books(vector<int> &A, int B) {
    //logic is to take --> min(maxSum)
    if(A.size() < B) return -1;
    int low = *min_element(A.begin(), A.end());
    int high = 0, ans = -1;
    for(auto &it : A) high += it;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(blackBox(mid, A, B)) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}
