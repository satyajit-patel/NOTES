#include<bits/stdc++.h>

using namespace std;
bool bi_search(vector<int> arr, int target)
{
    int n=arr.size();
    int low=0;
    int high=n-1;

    int mid=0; 
    while (low <= high)
    {
        mid=low+(high-low)/2;

        if(arr[mid] == target)
            return true;
        if(arr[mid] > target)
            high=mid-1;
        if(arr[mid] < target)
            low=low+1;
    }
    return false;
}
int main()
{
    vector<int> v{1,5,4,3,2};
    sort(v.begin(), v.end());
    //for(auto it : v)
        //cout<<it;
    int target=41;
    bool catchh = bi_search(v, target);
    if(catchh == true)
        cout<<"found";
    else
        cout<<"not found";

    return 0;
}