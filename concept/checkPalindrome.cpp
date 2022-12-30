#include<bits/stdc++.h>

using namespace std;
int main()
{
    cout<<"enter\n";
    string s; cin>>s;

    string s1 = s;
    reverse(s1.begin(), s1.end());

    if(s == s1) cout<<"palindrome\n";
    else cout<<"not palindrome\n";
    return 0;
}