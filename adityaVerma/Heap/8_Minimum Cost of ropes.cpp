// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution {
public:
    long long minCost(long long arr[], long long n) {
        std::multiset<long long> st;
        for(long long i=0; i<n; i++) st.insert(arr[i]);
        long long sum = 0;
        while(st.size() != 1) {
            auto small1 = st.begin();
            auto small2 = st.begin();
            small2++;
            long long newNum = (*small1) + (*small2);
            sum += newNum;
            st.insert(newNum);
            st.erase(small1);
            st.erase(small2);
        }
        return sum;
    }
};