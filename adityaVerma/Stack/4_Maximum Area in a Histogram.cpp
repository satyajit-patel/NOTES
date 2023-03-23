// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    vector<long long> nextSmallerElement(long long* arr, int n) {
        stack<long long> st;
        vector<long long> nse(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            else nse[i] = -1;
            st.push(i);
        }
        return nse;
    }
    
    vector<long long> previousSmallerElement(long long* arr, int n) {
        stack<long long> st;
        vector<long long> pse(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            else pse[i] = -1;
            st.push(i);
        }
        return pse;
    }
    
    long long getMaxArea(long long arr[], int n) {
        vector<long long > nse = nextSmallerElement(arr, n);
        vector<long long > pse = previousSmallerElement(arr, n);
        long long maxArea = INT_MIN;
        for(int i=0; i<n; i++) {
            if(nse[i] == -1) nse[i] = n; // if all ele are same, then Base would be same as arrays length
            long long Height = arr[i];
            long long Base = nse[i] - pse[i] - 1;
            long long Area = Height * Base;
            maxArea = std::max(maxArea, Area);
        }
        return maxArea;
    }
};