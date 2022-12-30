#include<iostream>
#include<map>
#include<set>
#include<algorithm>

using namespace std;
int main()
{
    map<int, string> mpp;
    mpp[20] = "Babu";
    mpp[21] = "Satya";
    mpp[22] = "Ankit";

    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<"\n";
    }

    multiset<int> ms ={1, 2, 3, 3, 4, 4, 5, 5};
    auto it = ms.find(3);
    ms.erase(it);
    ms.erase(ms.find(4)); //erase only the first occurance 
    ms.erase(5); //erase the all element
    for(auto i : ms) cout<<i<<" ";

    cout<<"\n";
    string s = "bca";

    //always sort the string inorder to get all permutation
    sort(s.begin(), s.end());
    do{
        cout<<s<<"\n";
    }
    while(next_permutation(s.begin(), s.end()));
    return 0;
}