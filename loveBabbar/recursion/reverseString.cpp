#include<bits/stdc++.h>
using namespace std;

void reverseUsingLoop(int i, int j, string& s) {
    while(i < j) {
        std::swap(s[i++], s[j--]);
    } 
}
void reverseUsingRecursion(int i, int j, string& s) {
    //base case
    if(i > j) return;
    
    std::swap(s[i], s[j]);
    //recursive case
    reverseUsingLoop(i+1, j-1, s);
}
int main() {
    string s1 = "ABCDE";
    string s2 = "VWXYZ";
    reverseUsingLoop(0, 4, s1);
    reverseUsingRecursion(0, 4, s2);
    cout<<s1<<endl<<s2<<endl;
    return 0;
}