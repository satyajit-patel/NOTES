#include<bits/stdc++.h>

#define endl "\n"
#define newLine std::cout<<"\n";
#define int long long int
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define pb push_back
const int MOD = 1e9 + 7;

namespace my {

}

// ------------------------------------------------

// link :- 

class Node {
public:
  char data;
  bool terminal;
  std::vector<Node*> arr;

  Node(char data) {
    this->data = data;
    terminal = false;
    arr.resize(26, NULL);
  }
};

class Trie {
public:
  void insert(Node* root, std::string s) {
    // base case
    if(s.size() == 0) {
      root->terminal = true;
      return;
    }

    // 1 case pre work
    char ch = s[0];
    int chIndex = ch - 'a';
    Node* child;
    if(root->arr[chIndex] != NULL) child = root->arr[chIndex];
    else {
      child = new Node(ch);
      root->arr[chIndex] = child;
    }

    // recursive case
    insert(child, s.substr(1));
  }

  bool search(Node* root, std::string s) {
    // base case
    if(s.size() == 0) return root->terminal;

    // 1 case pre work
    char ch = s[0];
    int chIndex = ch - 'a';
    Node* child;
    if(root->arr[chIndex] != NULL) child = root->arr[chIndex];
    else return false;

    // recursive case
    return search(child, s.substr(1));
  }
};

void input() {
  Node* root = new Node('-');
  Trie trie;
  trie.insert(root, "code");
  trie.insert(root, "codehelp");
  trie.insert(root, "satya");
  trie.insert(root, "satyajit");

  if(trie.search(root, "satyajit") == true) std::cout<<"yes it's present\n";
  else  std::cout<<"Nope it's not present\n";
  if(trie.search(root, "loveBabbar") == true) std::cout<<"yes it's present\n";
  else  std::cout<<"Nope it's not present\n";
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
