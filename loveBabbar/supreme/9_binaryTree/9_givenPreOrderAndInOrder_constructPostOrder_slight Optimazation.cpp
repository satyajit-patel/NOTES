#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define newLine std::cout<<"\n";
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------


// link :- 

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

void getPreOrder(Node* root, vi& preOrder) {
  // base case
  if(!root) return;

  // 1 case pre work
  preOrder.push_back(root->data);
  
  // recursive case
  getPreOrder(root->left, preOrder);
  getPreOrder(root->right, preOrder);
}

vvi getLevelOrder(Node* root) {
  vvi levelOrder;
  vi temp;
  std::queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    int N = q.size();
    for(int i=0; i<N; i++) {
      Node* node = q.front();
      q.pop();
      temp.push_back(node->data);
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    }
    levelOrder.push_back(temp);
    temp.clear();
  }
  return levelOrder;
}

Node* builtdTreeFromPostOrderAndInOrder(vi& postOrder, std::unordered_map<int, int>& inOrderMap, int& postOrderEndIndex, int inOrderStartIndex, int inOrderEndIndex) {
  // base case
  if(postOrderEndIndex < 0) return NULL;
  if(inOrderStartIndex > inOrderEndIndex) return NULL;

  // 1 case pre work
  int element = postOrder[postOrderEndIndex--];
  Node* root = new Node(element);
  int midIndex = inOrderMap[element]; // (1)

  // recursive case
  root->right = builtdTreeFromPostOrderAndInOrder(postOrder, inOrderMap, postOrderEndIndex, midIndex+1, inOrderEndIndex); // in postOrder first make the call for right subtree. This is only the edge case 
  root->left = builtdTreeFromPostOrderAndInOrder(postOrder, inOrderMap, postOrderEndIndex,inOrderStartIndex, midIndex-1);
  return root;
}

void input() {
  // vi  preOrder = {5, 1, 3, 4, 2};
  vi  inOrder = {3, 1, 4, 5, 2};
  vi  postOrder = {3, 4, 1, 2, 5};
  std::unordered_map<int, int> inOrderMap; 
  for(int i=0; i<inOrder.size(); i++) inOrderMap[inOrder[i]] = i;
  int postOrderEndIndex = inOrder.size()-1;
  int inOrderStartIndex = 0;
  int inOrderEndIndex = inOrder.size()-1;
  
  Node* root = builtdTreeFromPostOrderAndInOrder(postOrder, inOrderMap, postOrderEndIndex, inOrderStartIndex, inOrderEndIndex);

  vvi levelOrder = getLevelOrder(root);
  for(auto &row : levelOrder) {
    for(auto &it : row) std::cout<<it<<" ";
    std::cout<<"\n";
  }
  
  vi preOrder;
  getPreOrder(root, preOrder);
  newLine;
  for(auto &it : preOrder) cout<<it<<" ";
  newLine;
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
