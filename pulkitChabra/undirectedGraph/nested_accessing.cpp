#include<bits/stdc++.h>

using namespace std;
int main()
{
    map<string, vector<pair<int, vector<string> > > > m;


    m.insert(make_pair("ranjha", vector<pair<int, vector<string>>>
    {
    make_pair(100, vector<string>{"loki1", "loki2", "loki3", "loki4", "loki5...."}),
    make_pair(200, vector<string>{"loki10", "loki20", "loki30", "loki40", "loki50...."}),
    make_pair(300, vector<string>{"loki100", "loki200", "loki300", "loki400", "loki500...."})
    }
    ) );

    for(auto it : m)
        cout<<it.first<<"\n";
    cout<<m["ranjha"][2].first<<"\n";
    cout<<m["ranjha"][2].second[4]<<"\n"; //------>access the string
    cout<<m["ranjha"][2].second[4][2]; //---->access the charecter of string




    return 0;
}