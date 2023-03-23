#include<bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=1
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    vector<int> nse(n, -1);
    for(int i=n-1; i>=0; i--) {
        //if smaller comes then pop all the bigger
        while(!s.empty() && s.top() >= arr[i]) s.pop();
        if(!s.empty()) nse[i] = s.top();
        s.push(arr[i]);
    }
    return nse;
}