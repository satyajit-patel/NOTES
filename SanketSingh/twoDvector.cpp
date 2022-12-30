#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<vector<int>> vec;

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);

    vector<int> v3{100,200,300,400,500};

    //push the all vector<int> into vector
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);

    for(auto vctr: vec)//vctr(vector it self) is just a variable name 
    {
        for(auto it: vctr)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}
