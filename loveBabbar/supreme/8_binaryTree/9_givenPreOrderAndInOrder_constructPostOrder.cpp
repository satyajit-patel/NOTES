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

void getPostOrder(Node* root, vi& postOrder) {
  // base case
  if(!root) return;

  // recursive case
  getPostOrder(root->left, postOrder);
  getPostOrder(root->right, postOrder);

  // 1 case post work
  postOrder.push_back(root->data);
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

Node* builtdTreeFromPreOrderAndInOrder(vi& preOrder, vi& inOrder, int N, int& preOrderStartIndex, int inOrderStartIndex, int inOrderEndIndex) {
  // base case
  if(preOrderStartIndex >= N) return NULL;
  if(inOrderStartIndex > inOrderEndIndex) return NULL;

  // 1 case pre work
  int element = preOrder[preOrderStartIndex++];
  Node* root = new Node(element);
  int midIndex = std::find(inOrder.begin(), inOrder.end(), element) - inOrder.begin();

  // recursive case
  root->left = builtdTreeFromPreOrderAndInOrder(preOrder, inOrder, N, preOrderStartIndex,inOrderStartIndex, midIndex-1);
  root->right = builtdTreeFromPreOrderAndInOrder(preOrder, inOrder, N, preOrderStartIndex, midIndex+1, inOrderEndIndex);

  // store and return return
  return root;
}

void input() {
  vi  preOrder = {5, 1, 3, 4, 2};
  vi  inOrder = {3, 1, 4, 5, 2};
  int N = preOrder.size();
  int preOrderStartIndex = 0;
  int inOrderStartIndex = 0;
  int inOrderEndIndex = N-1;
  
  Node* root = builtdTreeFromPreOrderAndInOrder(preOrder, inOrder, N, preOrderStartIndex, inOrderStartIndex, inOrderEndIndex);

  vvi levelOrder = getLevelOrder(root);
  for(auto &row : levelOrder) {
    for(auto &it : row) std::cout<<it<<" ";
    std::cout<<"\n";
  }
  
  vi postOrder;
  getPostOrder(root, postOrder);
  newLine;
  for(auto &it : postOrder) cout<<it<<" ";
  newLine;
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
