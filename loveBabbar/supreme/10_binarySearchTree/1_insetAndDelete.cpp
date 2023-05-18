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
    this->left = this->right = NULL;
  }
};

void getInOrder(Node* root, vi& inOrder) {
  // base case
  if(!root) return;

  // recursive case
  getInOrder(root->left, inOrder);

  // 1 case in work
  inOrder.push_back(root->data);
  
  getInOrder(root->right, inOrder);
}

void getLevelOrder(Node* root, vvi& levelOrder, vi temp) {
  std::queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    int N = q.size();
    for(int i=0; i<N; i++) {
      root = q.front();
      q.pop();
      temp.push_back(root->data);
      if(root->left) q.push(root->left);
      if(root->right) q.push(root->right);
    }
    levelOrder.push_back(temp);
    temp.clear();
  }
}

Node* insertBST(int data, Node* root) {
  if(root == NULL) {
    root = new Node(data);
    return root;
  }

  if(data < root->data) root->left = insertBST(data, root->left);
  else root->right = insertBST(data, root->right);
  return root;
}

void makeBST(Node* &root) {
  std::cout<<"enter data\n";
  while(1) {
    int data; std::cin>>data;
    if(data != -1) {
      root = insertBST(data, root);
    }
    else break;
  }
}

void print(Node* root) {
  vi inOrder;
  getInOrder(root, inOrder);
  std::cout<<"\ninOrder :- \n";
  for(auto &it : inOrder) std::cout<<it<<" ";
  newLine;

  vvi levelOrder;
  getLevelOrder(root, levelOrder, {});
  std::cout<<"\nlevelOrder :- \n";
  for(auto &row : levelOrder) {
    for(auto &it : row) std::cout<<it<<" ";
    newLine;
  }
  newLine;
}

int maxVal(Node* root) {
  while(root->right != NULL) root = root->right;
  return root->data;
}

Node* deleteBST(Node* root, int target) {
  if(!root) return NULL;
  if(target == root->data) {
    if(!root->left && !root->right) {
      delete root;
      return NULL;
    }
    else if(root->left && !root->right) {
      Node* child = root->left;
      delete root;
      return child;
    }
    else if(!root->left && root->right) {
      Node* child = root->right;
      delete root;
      return child;
    }
    else if(root->left && root->right) {
      int inOrderPre = maxVal(root->left);
      root->data = inOrderPre;
      root->left = deleteBST(root->left, inOrderPre);
      return root;
    }
  }
  else if(target < root->data) root->left = deleteBST(root->left, target);
  else if(target > root->data) root->right = deleteBST(root->right, target);
  return root;
}

void input() {
  Node* root = NULL;
  
  makeBST(root);
  print(root);
  
  root = deleteBST(root, 20);
  print(root);
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
