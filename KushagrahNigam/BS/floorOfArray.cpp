#include<bits/stdc++.h>

using namespace std;


bool check(vector<int> &vec, int mid, int k)
{
    return (vec[mid] <= k);

}


int floorUsingBS(vector<int> &vec, int k)
{
    int low = 0, high = vec.size() - 1;
    int ans = -1;
    while(high >= low){

        int mid = (low+high)/2;
        if(check(vec, mid, k)){
            ans = vec[mid];
            low = mid +1 ;
        }
        else high = mid - 1;


    }
    return ans;
}



int floorUsingLbound(multiset<int> &ms, int k)
{
    auto it = ms.lower_bound(k);
    if(*it == k && it != ms.end()) return *it;
    else{
        it--;
        return *it;
    }
}


int main()
{
    cout<<"enter size, key and array\n";
    int n, k; cin>>n>>k;
    multiset<int> ms;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        vec.push_back(x);
        ms.insert(x);
    }
    sort(vec.begin(), vec.end());
    cout<<"\n";
    for(auto it : ms) cout<<it<<" ";
    int ans = floorUsingBS(vec, k);
    //int ans = floorUsingLbound(ms, k);
    cout<<"\n";
    cout<<"floor of "<<k<<" is : "<<ans<<"\n";

    return 0;
}