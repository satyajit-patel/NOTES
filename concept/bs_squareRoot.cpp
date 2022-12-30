#include<iostream>

using namespace std;
int target;
bool check(int x)
{
    return (x*x <= target);
}
int main()
{
    cout<<"enter target\n";
    cin>>target;

    int low=0;
    int high=target;

    int ans = -1;
    while(high >= low)
    {
        int mid = (low + high)/2;
        if(check(mid)){
            ans = mid;
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}