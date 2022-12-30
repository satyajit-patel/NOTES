/************************************************************

    Following is the TreeNode class structure
    https://bit.ly/3GtxyQa
    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<bits/stdc++.h>
#define vi vector<int>
vector<int> getLeftView(TreeNode<int> *root) {
    //    Write your code here
   vi ans, tmp;
   if(!root) return ans;
   queue<TreeNode<int>*> q;
   q.push(root);
   while(!q.empty()) {
       int n = q.size();
       for(int i=0; i<n; i++) {
           root = q.front();
           q.pop();
           tmp.push_back(root->data);
           if(root->left) q.push(root->left);
           if(root->right) q.push(root->right);
       }
       ans.push_back(tmp[0]); 
       tmp.clear();
   }
   return ans;   
}