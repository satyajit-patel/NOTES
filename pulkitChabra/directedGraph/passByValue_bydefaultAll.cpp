#include<bits/stdc++.h>

using namespace std;
void solve(vector<int> &loki1)
{
    loki1.push_back(100);  
    loki1.push_back(200);
    loki1.push_back(300);
}
int main()
{
    vector<int> loki1{1,2,3,4,5};
    solve(loki1);
    for(int &it : loki1)//in this format it becomes the elements itself so & is optional
        cout<<it<<" ";
    return 0;
}