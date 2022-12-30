#include<bits/stdc++.h>
#define MAX 50

using namespace std;

vector<vector<int> > DP(MAX, vector<int> (MAX, -1));
int D1[MAX], D2[MAX]; //dimentions

int cost(int i, int j)
{
    if(i == j)
        return 0;
    if(DP[i][j] != -1)
        return DP[i][j];
    else{
        DP[i][j]= 900000;//like infinity just to compare
        for (int k = i; k < j; k++)
        {
            DP[i][j]= min(DP[i][j], cost(i, k) + cost(k+1, j) + D1[i]*D2[j]*D2[k]);
        }
        return DP[i][j];
    }

}
int main()
{
    int n;
    cout<<"no of matrix\n";
    cin>>n;
    cout<<"enter dimensions\n";
    for (int i = 0; i < n; i++)
    {
        cin>>D1[i]>>D2[i];
    }

    int min_cost= cost(0, n-1);
    cout<<min_cost;
    return 0;
}