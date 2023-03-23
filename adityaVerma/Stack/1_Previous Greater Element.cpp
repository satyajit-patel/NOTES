#include <bits/stdc++.h>
using namespace std;

vector<int> previousGreaterElement(int* arr, int n){
        stack<int> st;
        vector<int> pge(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[i] >= st.top()) st.pop();
            if(!st.empty()) pge[i] = st.top();
            else pge[i] = -1;
            st.push(arr[i]);
        }
        return pge;
    }
int main() {
    int n = 7;
    int arr[n] = {10, 4, 2, 20, 40, 12, 30};
    // Output : -1, 10, 4, -1, -1, 40, 40
    vector<int> pge = previousGreaterElement(arr, n);
    for(int i=0; i<n; i++) cout<<pge[i]<<" ";
    return 0;
}