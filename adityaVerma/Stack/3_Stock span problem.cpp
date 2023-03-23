// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
class Solution {
public:
    vector<int> previousGreaterElement(int* arr, int n){
        stack<int> st;
        vector<int> pge(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[i] >= arr[st.top()]) st.pop();
            if(!st.empty()) pge[i] = st.top();
            else pge[i] = -1;
            st.push(i);
        }
        return pge;
    }

    vector<int> calculateSpan(int price[], int n) {
        vector<int> ans(n);
        vector<int> pge = previousGreaterElement(price, n);
        for(int i=0; i<n; i++) ans[i] = i - pge[i];
        return ans;
    }
};