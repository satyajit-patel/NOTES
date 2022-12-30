#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vii vector<vector<int>>
#define vi vector<int>

int tree[2 * 100005];
int arr[2 * 100005];
void build(int root, int low, int high) {
    if(low == high) {
        tree[root] = arr[low];
        return;
    }
    
    int mid = (low+high)/2;
    build(2*root, low, mid);
    build(2*root+1, mid+1, high);
    tree[root] = min(tree[2*root], tree[2*root+1]);
    //cout<<tree[root]<<" ";
}
int minRange(int root, int low, int high, int L, int R) {
    if(low > R || high < L) return INT_MAX; //outOfBound
    if(low >= L && high <= R) return tree[root]; //insiseRange
    
    int mid = (low+high)/2;
    int q1 = minRange(2*root, low, mid, L, R);
    int q2 = minRange(2*root+1, mid+1, high, L, R);
    return min(q1, q2);
}
int main() {
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    build(1, 0, n-1);
    cout<<minRange(1, 0, n-1, 1, 2)<<endl;
    return 0;
}