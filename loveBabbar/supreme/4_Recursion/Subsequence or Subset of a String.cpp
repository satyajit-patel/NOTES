#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- 

void f(int i, std::string& s, std::string& output) { // pass by reference
    // base case
    if(i >= s.size()) {
        std::cout<<"{"<<output<<"}"<<endl;
        return;
    }

    // include
    output.push_back(s[i]);
    f(i+1, s, output);
    // backtrack
    output.pop_back();

    // exclude
    f(i+1, s, output);
}

// void f(int i, std::string& s, std::string output) { // pass by value
//     // base case
//     if(i >= s.size()) {
//         std::cout<<"{"<<output<<"}"<<endl;
//         return;
//     }

//     // include
//     f(i+1, s, output + s[i]);

//     // exclude
//     f(i+1, s, output);
// }

void input() {
    std::string s = "abc";
    std::string output = "";
    f(0, s, output);
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}