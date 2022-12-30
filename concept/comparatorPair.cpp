#include<bits/stdc++.h>

using namespace std;

bool comp(pair<string, int> &a, pair<string, int> &b)
{
    return (a.second < b.second);
}
int main()
{
    vector<pair<string, int>> vec;

    /*
    string arr1[] = {"Ankit", "Satya", "Babu"};
    int arr2[] = {22, 21, 20};
    
    //int n = sizeof(arr1); gives number of bytes to occupy(used in parameter at memset)
    int n = sizeof(arr2)/sizeof(int);
    for(int i=0; i<n; i++){
        vec.push_back(make_pair(arr1[i], arr2[i]));
    }
    */

    //or

    vec ={{"Ankit", 22}, {"Satya", 21}, {"Babu", 20}, {"Subrat", 19}};


    /*
    cout<<"\nbefore sorting :-\n";
    for(int i=0; i<n; i++){
        cout<<vec[i].first<<"\n";
    }
    sort(vec.begin(), vec.end(), comp);
    cout<<"\nafter sorting :-\n";
    for(int i=0; i<n; i++){
        cout<<vec[i].first<<"\n";
    }
    */
   cout<<"\nbefore sorting :-\n";
   for(auto it : vec){
       cout<<it.first<<"\n";
   }
   sort(vec.begin(), vec.end(), comp);
   cout<<"\nafter sorting :-\n";
   for(auto it : vec){
       cout<<it.first<<"\n";
   }
    return 0;
}