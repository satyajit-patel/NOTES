// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=1
#include <bits/stdc++.h> 
#define ADJ unordered_map<int, set<pair<int, int>>>
vector<int> pq(int root, int n, ADJ& adj) {
    vector<int> dist(n, INT_MAX);
    dist[root] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({dist[root] * -1, root});
    
    while(!pq.empty()) {
        int cost = pq.top().first * -1;
        root     = pq.top().second;
        pq.pop();
        for(auto &child : adj[root]) {
            int nextNode = child.first;
            int weight   = child.second;
            if(cost+weight < dist[nextNode]) {
                dist[nextNode] = cost + weight;
                pq.push({dist[nextNode] * -1, nextNode});
            }
        }
    }
    return dist;
}
vector<int> dijkstra(vector<vector<int>>& vec, int v, int e, int src) {
    // prepare adj list
    ADJ adj;
    for(int i=0; i<vec.size(); i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].insert({v, w});
        adj[v].insert({u, w});
    }
    
    vector<int> ans = pq(src, v, adj);
    return ans;
}
