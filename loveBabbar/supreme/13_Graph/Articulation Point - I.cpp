// https://practice.geeksforgeeks.org/problems/articulation-point-1/1
class Solution {
private:
    int timer;
    vector<int> in, low, mark, vis;
    void dfs(int root, int par, vector<int> adj[]) {
        vis[root] = 1;
        in[root] = low[root] = timer++;
        int children = 0;
        for (auto &child : adj[root]) {
            if (child == par) continue;
            if (!vis[child]) {
                dfs(child, root, adj);
                low[root] = std::min(low[root], low[child]);
                if(low[child] >= in[root] && par != -1) mark[root] = 1; // change 1
                children++;
            }
            else low[root] = std::min(low[root], in[child]);
        }
        if(children > 1 && par == -1) mark[root] = 1;
    }
public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        timer = 0;
        in.resize(V, 0);
        low.resize(V, 0);
        vis.resize(V, 0);
        mark.resize(V, 0);
        for(int i=0; i<V; i++) if(!vis[i]) dfs(i, -1, adj);
        vector<int> ans;
        for(int i=0; i<V; i++) if(mark[i] == 1) ans.push_back(i);
        if(ans.size() == 0) return {-1};
        return ans;
    }
};
