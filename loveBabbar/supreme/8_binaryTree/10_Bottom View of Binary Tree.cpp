// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    vector <int> bottomView(Node *root) {
        std::vector<int> bottomView;
        if(!root) return bottomView;
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
            m[verticalDist] = node->data;
            if(node->left) q.push({node->left, verticalDist-1});
            if(node->right) q.push({node->right, verticalDist+1});
        }
        for(auto &it : m) bottomView.push_back(it.second);
        return bottomView;
    }
};