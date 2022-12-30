#include<bits/stdc++.h>

using namespace std;
int main()
{
    cout<<"enter\n";
    string s;
    getline(cin, s);
    stringstream iss(s);
    string word;

    //print the words which contains char a
    while(iss >> word){
        auto it = word.find("a");//returns string::npos if position not found like ms.end() in ms
        if(it != string::npos) cout<<word<<" ";
    }
    return 0;
}