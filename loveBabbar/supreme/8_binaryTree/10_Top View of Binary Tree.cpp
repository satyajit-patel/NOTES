/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution {
public:
    vector<int> topView(Node *root) {
        std::vector<int> topView;
        if(!root) return topView;
        Node* node = root;
        int verticalDist = 0;
        std::map<int, int> m;
        std::queue<std::pair<Node*, int>> q;
        q.push({node, verticalDist});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            node = it.first;
            verticalDist = it.second;
            if(m.find(verticalDist) == m.end()) m[verticalDist] = node->data;
            if(node->left) q.push({node->left, verticalDist-1});
            if(node->right) q.push({node->right, verticalDist+1});
        }
        for(auto &it : m) topView.push_back(it.second);
        return topView;
    }

};
