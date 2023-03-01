//https://www.codingninjas.com/codestudio/problems/allocate-books_1090540
bool check(int mid, vector<int>& A, int N, int M) {
    int student = 1;
    int sum = 0;
    for(int i=0; i<N; i++) {
        if(sum+A[i] <= mid) sum += A[i];
        else {
            student++;
            if(student > M || A[i] > mid) return false;
            sum = A[i];
        }
    }
    return true;
}
int allocateBooks(vector<int>& arr, int n, int m) {
    if(n < m) return -1;
    int total = 0;
    for(auto &it : arr) total += it;
    int ans = -1;
    //searchSpace is from low to high
    int low = 0;
    int high = total;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(check(mid, arr, n, m)) {
            ans = mid;
            //we need as min as possible
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}