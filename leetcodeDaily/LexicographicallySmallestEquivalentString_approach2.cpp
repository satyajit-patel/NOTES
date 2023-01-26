// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/
class DSU {
public:
    vector<int> parent, height;
    DSU(int n) {
        parent.resize(n, -1);
        height.resize(n, -1);
    }
    int findParent(int x) {
        if(parent[x] == -1) return x;
        return parent[x] = findParent(parent[x]);
    }
    void unionByHeight(int u, int v) {
        int x = findParent(u);
        int y = findParent(v);
        if(x == y) return;

        // if(height[x] < height[y]) parent[x] = y;
        // else if(height[y] < height[x]) parent[y] = x;
        // else {
        //     parent[x] = y;
        //     height[y]++;
        // }

        parent[std::max(x, y)] = std::min(x, y); 
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        for(int i=0; i<s1.size(); i++) {
            dsu.unionByHeight(s1[i] - 'a', s2[i] - 'a');
        }
        for(int i=0; i<baseStr.size(); i++) {
            baseStr[i] = dsu.findParent(baseStr[i] - 'a') + 'a';
        }
        return baseStr;
    }
};