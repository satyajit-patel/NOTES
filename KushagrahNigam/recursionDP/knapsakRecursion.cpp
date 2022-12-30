#include<iostream>

using namespace std;

int knapsak(int val[], int wt[], int w, int n){
    //baseCase
    if(w == 0 || n == 0) return 0;


    //recursiveCase
    if(wt[n-1] <= w){
        //takeIt
        int x = val[n-1] + knapsak(val, wt, w-wt[n-1], n-1);

        //!takeIt
        int y = knapsak(val, wt, w, n-1);

        return max(x, y);
    }
    else{
        //discard
        return knapsak(val, wt, w, n-1);
    }
}
int main()
{
    int n=6;
    int w=25;
    int val[n] = {15, 12, 25, 27, 16, 6};
    int wt[n] = {10, 7, 5, 9, 4, 3};

    cout<<knapsak(val, wt, w, n);
    return 0;
}