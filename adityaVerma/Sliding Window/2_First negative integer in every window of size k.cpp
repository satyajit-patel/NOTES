// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K) {
    std::vector<long long> ans;
    std::deque<long long> dq;
    
    // step1
    for(int i=0; i<K; i++) if(A[i] < 0) dq.push_back(A[i]);
    if(dq.size() != 0) ans.push_back(dq.front());
    else ans.push_back(0);
    
    // step2
    int i = 0;
    int j = K;
    while(i<N && j<N) {
        if(A[j] < 0) dq.push_back(A[j]);
        j++;
        if(A[i] == dq.front()) dq.pop_front();
        i++;
        if(dq.size() != 0) ans.push_back(dq.front());
        else ans.push_back(0);
    }
    return ans;
}