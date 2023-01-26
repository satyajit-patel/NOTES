// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true
long arrayManipulation(int n, vector<vector<int>> queries) {
    // given 1 based indexing
    vector<long> arr(n+10, 0);
    for(auto &row : queries) {
        int L = row[0];
        int R = row[1]; 
        int K = row[2];
        arr[L] += K;
        arr[R+1] -= K;
    }
    for(int i=1; i<arr.size(); i++) {
        arr[i] += arr[i-1];
    }
    return *max_element(arr.begin(), arr.end());
}
