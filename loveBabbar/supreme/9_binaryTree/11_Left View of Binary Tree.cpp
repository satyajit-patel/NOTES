/*
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
vector<int> leftView(Node *root) {
    std::vector<int> leftView;
    if(!root) return leftView;
    Node* node = root;
    int level = 0;
    std::queue<Node*> q;
    q.push(node);
    while(!q.empty()) {
        int N = q.size();
        for(int i=0; i<N; i++) {
            node = q.front();
            q.pop();
            if(level == leftView.size()) leftView.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        level++;
    }
    return leftView;
}