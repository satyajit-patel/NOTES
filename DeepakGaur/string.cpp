#include<bits/stdc++.h>

using namespace std;
void solve1()
{
    string s;
    //cout<<"enter string\n";
    //cin>>s;

    for (int i = 0; i < 20; i++)
    {
        cout<<s<<" "<<s.size()<<endl;
        s= s+"a";
    }

    for (int i = 0; i < 10; i++)
    {
        s.pop_back();
    }
    cout<<"\n"<<s<<" "<<s.size();
}
void solve2()
{
    string s="its not who i am underneath but what i do defines me";

    //syntax: s.substr(start_index, length from start_index)
    cout<<s.size()<<endl;
    cout<<s.substr(0, 27)<<endl;
    cout<<s.substr(28, 3)<<endl;
    cout<<s.substr(32, 20)<<endl;
}
void alphabet()
{
    //funtions: islower(), isupper(), tolower, toUpper, isalpha
    string s= "Satyajit Patel 770001";

    cout<<islower(s[0])<<endl; 
    cout<<isupper(s[0])<<endl;

    cout<<s<<endl;
    s[0]= tolower(s[0]);
    cout<<s<<endl; 

    int count=0, num=0;
    /*for (int i = 0; i < s.size(); i++)
    {
        if(islower(s[i]) or isupper(s[i]))
            count++;
    }
    cout<<"number of alphabets="<<count;*/

    //or direct 
    //check how many alphabet and numbers present in a line
    for (int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i]))
            count++;
        if('0'<=s[i] && s[i]<='9')
            num++;
    }
    cout<<"number of alphabets="<<count;
    cout<<"\n"<<num<<endl;
    reverse(s.begin(), s.end());
    cout<<s;
}
int main()
{
    //solve1();
    //solve2();
    alphabet();
    return 0;
}