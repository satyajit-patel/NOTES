//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

int findMinOperation(int start, int end, vi &arr) {
    vi vis(end+1, 0);
    vis[start] = 1;
    queue<pair<int, int>> q;
    q.push({start, 0});
    while(!q.empty()) {
        int node = q.front().first;
        int step = q.front().second;
        q.pop();
        
        if(node == end) return step;
        for(int i=0; i<arr.size(); i++) {
            int dest = node * arr[i];
            if(dest <= end && !vis[dest]) {
                q.push({dest, step+1});
                vis[dest] = 1;
            }
        }
    }
    return -1;    
}
int main() {
    vi arr = {2, 5, 6};
    cout<<findMinOperation(3, 30, arr)<<endl;
    return 0;
}