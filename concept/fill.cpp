//test cases
//k= 3, fill = x;
//abcdef => abcdef
//abcdefe => abcdefexx
#include<bits/stdc++.h>

using namespace std;
vector<string> divideString(string s, int k, char fill)
{
    vector<string> ans;
    int n = s.size();
    string res = "";

    for(int i=0; i<n; i++){
        res += s[i];
        if(res.size() == k){
            ans.push_back(res);
            res.clear(); //or res = "";
        }
    }

    if(res.size() > 0 && res.size() != k){
        while(res.size() != k){
            res += fill;
        }
        ans.push_back(res);
    }
    return ans;
}
int main()
{
    cout<<"enter\n";
    string s; cin>>s;
    int k; cin>>k;
    char fill; cin>>fill;

    vector<string> vec;
    vec = divideString(s, k, fill);
    for(auto it : vec) cout<<it;
    return 0;
}