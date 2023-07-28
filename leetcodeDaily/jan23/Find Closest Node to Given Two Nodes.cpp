// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/
#define ADJ std::unordered_map<int, std::set<int>>
class Solution {
public:
    void f(int root, ADJ& adj, vector<int>& vis, vector<int>& dist, int distance) {
        vis[root]  = 1;
        dist[root] = distance;
        for(auto &child : adj[root]) {
            if(!vis[child]) f(child, adj, vis, dist, distance + 1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // prepare adj list
        ADJ adj;
        for(int i=0; i<edges.size(); i++) {
            if(edges[i] >= 0) {
                int u = i;
                int v = edges[i];
                // directed graph
                adj[u].insert(v);
            }
        }
        std::vector<int> vis1(edges.size(), 0);
        std::vector<int> vis2(edges.size(), 0);
        std::vector<int> dist1(edges.size(), -1);
        std::vector<int> dist2(edges.size(), -1);
        f(node1, adj, vis1, dist1, 0);
        f(node2, adj, vis2, dist2, 0);
        int ansNode = -1;
        int maxDist = edges.size();
        for(int i=0; i<edges.size(); i++) {
            if(dist1[i] != -1 && dist2[i] != -1) {
                int curDist = std::max(dist1[i], dist2[i]);
                if(curDist < maxDist) {
                    maxDist = curDist;
                    ansNode = i; 
                }
            }
        }
        return ansNode;
    }
};