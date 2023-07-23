#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

/*
       90--------------------------- level 0
    20    50------------------------ level 1
  11  13 --------------------------- level 2
*/ 

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

Node* buildTree() {
  std::cout<<"enter data\n";
  int data; std::cin>>data;

  // base case
  if(data == -1) return NULL;

  // recursive case
  Node* root = new Node(data);
  
  std::cout<<"enter data for left part of "<<data<<endl;
  root->left = buildTree();
  
  std::cout<<"enter data for right part of "<<data<<endl;
  root->right = buildTree();

  // return root node address
  return root;
}

vvi levelOrder(Node* root) {
  vvi levelOrder;
  if(!root) return levelOrder;
  std::queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    int N = q.size();
    vi level;
    for(int i=0; i<N; i++) {
      Node* node = q.front();
      q.pop();
      level.push_back(node->data);
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    }
    levelOrder.push_back(level);
  }
  return levelOrder;
}

void postOrder(Node* root, vi& postorder) {
  // base case
  if(!root) return;

  // recursive case
  postOrder(root->left, postorder);
  postOrder(root->right, postorder);
  postorder.push_back(root->data);
}

int height(Node* root) {
  // base case
  if(!root) return 0;
  
  // recursive case
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  // store and return
  int ans = std::max(leftHeight, rightHeight) + 1;
  return ans;
}

void input() {
  // Node* root = buildTree();
  // std::cout<<root->left->left->data<<endl;
  
  Node* root = new Node(90);
  Node* newNode = new Node(20);
  root->left = newNode;
  newNode = new Node(50);
  root->right = newNode;
  newNode = new Node(11);
  root->left->left = newNode;
  newNode = new Node(13);
  root->left->right = newNode;

  std::cout<<"\nlevelOrder\n";
  vvi levelorder = levelOrder(root);
  for(auto &row : levelorder) {
    for(auto &it : row) std::cout<<it<<" ";
    std::cout<<endl;
  }
  
  vi postorder;
  postOrder(root, postorder);
  std::cout<<"\npostOrder\n";
  for(auto &it : postorder) std::cout<<it<<" ";
  
  std::cout<<"\n\nHeight is "<<height(root)<<endl;
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
