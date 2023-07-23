// https://leetcode.com/problems/number-of-provinces/description/
class DSU {
private:
    std::vector<int> parent, size;
public:
    DSU(int N) {
        parent.resize(N);
        for(int i=0; i<N; i++) parent[i] = i;
        size.resize(N, 1);
    }

    int getParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = getParent(parent[node]);
    }

    void unionS(int u, int v) {
        int nu = getParent(u);
        int nv = getParent(v);
        if(nu == nv) return;
        if(size[nu] < size[nv]) {
	// smaller going to attached to bigger
	// so nu got attached to nv
	// so size of nv got increased by size of nu
            parent[nu] = nv;
            size[nv] += size[nu];
        }
        else {
            parent[nv] = nu;
            size[nu] += size[nv];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU* dsu = new DSU(isConnected.size()+1);
        for(int i=0; i<isConnected.size(); i++) {
            for(int j=0; j<isConnected[i].size(); j++) {
                if(isConnected[i][j] == true) {
                    int u = i+1;
                    int v = j+1;
                    if(dsu->getParent(u) != dsu->getParent(v)) dsu->unionS(u, v);
                }
            }
        }
        int cc = 0;
        for(int root=1; root<=isConnected.size(); root++) {
            if(dsu->getParent(root) == root) cc++;
        }
        return cc;
    }
};