#include<bits/stdc++.h>

using namespace std;
vector<int> getSum(vector<int> vec)
{
    int n = vec.size();
    vector<int> prefix(n);
    for(int i=0; i<n; i++){
        if(i == 0) prefix[i] = vec[i];
        else prefix[i] = vec[i] + prefix[i-1];
    }
    return prefix;
}
int prefixSum(vector<int> vec, int L, int R)
{
    vector<int> prefix = getSum(vec);
    int ans = prefix[R];
    if(L > 0) ans -= prefix[L-1];
    return ans;
}
int main()
{
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> vec(n);
        for(auto &it : vec) cin>>it;
        int q; cin>>q;
        while(q--){
            int l, r; cin>>l>>r;
            cout<<prefixSum(vec,--l,--r)<<"\n";
        }   
    }
    return 0;
}