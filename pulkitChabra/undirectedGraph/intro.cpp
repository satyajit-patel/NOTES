#include<bits/stdc++.h>

using namespace std;
void print_neighbour_nodes(vector<vector<int>> v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for(int nb : v[i])
            cout<<nb<<" ";
        cout<<"\n";
    }
}
int main()
{
    cout<<"enter number of nodes\n";
    int n; cin>>n;
    vector<vector<int>> vec(n+1); 
    for(int i = 1; i <= n-1; i++) //becoz for n nodes.. no of edge is (n-1)
    {
        cout<<"enter 2 nodes\n";
        int u,v; 
        cin>>u>>v;//input order dosnt matter in cin..we can give verticaly or horizontaly

        //connect the edge
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    print_neighbour_nodes(vec,n);
    return 0;
}