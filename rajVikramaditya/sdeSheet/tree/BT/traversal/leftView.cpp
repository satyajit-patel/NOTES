/* A binary tree node
https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
#define vi vector<int>
void recursion(Node* root, int level, vi &ans) {
    if(!root) return;
    
    if(level == ans.size()) ans.push_back(root->data);
    recursion(root->left, level+1, ans);
    recursion(root->right, level+1, ans);
}
vector<int> leftView(Node *root) {
   // Your code here
   vi ans;
   if(!root) return ans;
   recursion(root, 0, ans);
   return ans;
}