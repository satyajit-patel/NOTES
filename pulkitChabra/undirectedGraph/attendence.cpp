//if two or more student have same name then shout their first and last name..
//other wise shout only first name
#include<bits/stdc++.h>

using namespace std;

int  main()
{
    cout<<"enter no of names\n";
    int n; cin>>n;

    //pair is same as array..syntactically just it take only two value
    pair<string, string> arr[n];
    map<string,int> m;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
        m[arr[i].first] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        if(m[arr[i].first] ==1)
            cout<<arr[i].first<<"\n";
        else
            cout<<arr[i].first<<" "<<arr[i].second<<"\n";
    }
    return 0;
}