 #include<bits/stdc++.h>
using namespace std;

void nextGreaterElement(vector<int> &arr, int n, vector<int> &nge) {
    stack<int> st;
    for(int i=n-1; i>=0; i--) { //i.e monotonically Decresing Oreder
        while(st.size() && st.top() <= arr[i]) {
            st.pop();
        }
        if(st.size()) nge[i] = st.top();
        st.push(arr[i]);
    }
}
int main() {
    int n = 9;
    vector<int> arr = {2,5,1,3,7,2,4,9,7};
    vector<int> nge(n, -1);
    nextGreaterElement(arr,n,nge);
    for(auto &it:nge) cout<<it<<" ";
    return 0;
}