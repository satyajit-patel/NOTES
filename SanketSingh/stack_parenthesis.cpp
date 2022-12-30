#include<bits/stdc++.h>

using namespace std;
int check(string str)
{
    stack<char> s;

    for(char ch: str)
    {
        if(ch == '(')
            s.push(ch);
        else if(s.empty())
            return false;
        else
            s.pop();
    }
    
    if(s.empty())
        return true;
    return false;
}
int main()
{
    string str="(((())";
    bool b=check(str);

    if(b == true)
        cout<<"matching\n";
    else
        cout<<"not matching\n";

    return 0;
}