#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define newLine std::cout<<"\n";
// #define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link :- 

void input() {
  // arr[i] == *(arr+i) // observatin
  // arr[1][1][2] == *(*(*(arr+1)+1)+2)
  
  // int arr[5] = {10,20,30,40,50};
  // std::cout<<arr[4]<<" "<<(arr+2)[2]<<" "<<(arr+5)[-1]<<" "<<(arr-1)[5];

  int arr[3][5] = {{1,2,3,4,5}, {10,20,30,40,50}, {100,200,300,400,500}};
  for(int i=0; i<3; i++) {
    for(int j=0; j<5; j++) std::cout<<arr[i][j]<<" ";
    newLine;
  }
  std::cout<<arr[1][4]<<" "<<*(*(arr+1)+4)<<" "<<*(arr[1]+4)<<" "<<(*(arr+1))[4];

  /*
    U -> unary (++, --, *, &)  -------------------------> right to left
    A -> arithmatic
        // priority
        -> (%, /, *)
        -> (+, -)
    S -> shift (<<, >>)
    C -> comparision (<, >, <=, >=, ==, !=)
    B -> bitwise (&, |, ^)
    L -> logical (&&, ||)
    A -> assignment (=, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=) --> right to left
    C -> comma (,)
  */
  
  // int arr[] = {1,2,3,4,5};
  // int *p = arr;
  // *++p += 200; // unary are right associative(so ist increase, then go inside)
  // std::cout<<*p<<" "<<arr[1];
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
