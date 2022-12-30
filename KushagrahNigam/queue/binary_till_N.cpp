#include<bits/stdc++.h>

using namespace std;
int main()
{
    cout<<"enter\n";
    int n;  cin>>n;
    queue<string> q;
    q.push("1");

    for(int i=0;    i<n;    i++){
        string s = q.front();
        q.pop();
        cout<<s<<" ";

        s.push_back('0');
        q.push(s);
        s.pop_back();

        s.push_back('1');
        q.push(s);
    }
    return 0;
}