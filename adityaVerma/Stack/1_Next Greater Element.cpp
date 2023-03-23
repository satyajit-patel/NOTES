// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
    public:
    vector<long long> nextLargerElement(vector<long long>& arr, int n){
        stack<long long> st;
        vector<long long> nge(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[i] >= st.top()) st.pop();
            if(!st.empty()) nge[i] = st.top();
            else nge[i] = -1;
            st.push(arr[i]);
        }
        return nge;
    }
};