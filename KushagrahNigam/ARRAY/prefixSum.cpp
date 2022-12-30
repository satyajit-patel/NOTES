#include<bits/stdc++.h>

using namespace std;
vector<int> getProduct(vector<int> vec)
{
    int n = vec.size();
    vector<int> prefix(n);
    for(int i=0; i<n; i++){
        if(i == 0){
            prefix[i] = vec[i];
            continue;
        }
        prefix[i] = vec[i] * prefix[i-1];
    }
    return prefix;
}
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
int prefixProduct(vector<int> vec, int L, int R)
{
    vector<int> prefix = getProduct(vec);
    int ans = prefix[R];
    if(L > 0) ans /= prefix[L-1];
    return ans;
}
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    cout<<prefixSum(vec,4,5)<<" "<<prefixProduct(vec,4,5);
    return 0;
}