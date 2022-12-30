#include<bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/next-greater-element_920451
vector<int> nextGreaterElement(vector<int>& arr, int n){
    stack<int> s;
    vector<int> nge(n, -1);
    for(int i=n-1; i>=0; i--) {
        //if bigger comes then pop all the smaller
        while(!s.empty() && s.top() <= arr[i]) s.pop();
        if(!s.empty()) nge[i] = s.top();
        s.push(arr[i]);
    }
    return nge;
}