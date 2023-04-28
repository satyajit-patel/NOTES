#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link:- 



void f1(string& s, vector<string>& v1) {
  do {
    v1.push_back(s);
  }
  while(std::next_permutation(s.begin(), s.end()));
}
void f2(string& s, vector<string>& v2, int i=0) {
  // base case
  if(i >= s.size()) {
    v2.push_back(s);
    return;
  }

  // recursive case
  for(int j=i; j<s.size(); j++) {
    std::swap(s[i], s[j]);
    f2(s, v2, i+1);
    std::swap(s[i], s[j]);
  }
}

void input() {
  std::string s = "abc";
  std::vector<std::string> v1;
  std::vector<std::string> v2;
  f1(s, v1);
  f2(s, v2);
  for(int i=0; i<v1.size(); i++) {
    cout<<v1[i]<<" "<<v2[i]<<endl;
  }
}