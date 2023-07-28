// int par[26];
    
//     int find(int x){
//         if(par[x]==-1) return x;
//         return par[x]=find(par[x]);
//     }
    
//     void Union(int x, int y) {
//         x = find(x);
//         y = find(y);
        
//         if (x != y) 
//             par[max(x, y)] = min(x, y); 
//     }
	
//     string smallestEquivalentString(string s1, string s2, string baseStr) {
        
//         memset(par, -1, sizeof(par));
        
//         for (auto i = 0; i < s1.size(); ++i) 
//             Union(s1[i] - 'a', s2[i] - 'a');
        
//         for(auto i=0;i<baseStr.size();i++) 
//             baseStr[i]=find(baseStr[i]-'a')+'a';

//         return baseStr;
//     }


// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/
class DSU {
public:
    vector<int> parent, height;
    DSU(int n) {
        parent.resize(n);
        height.resize(n, 0);
        for(int i=0; i<n; i++) {
        parent[i] = i;
        }
    }
    int findRoot(int u) {
        if(u == parent[u]) return u;
        return parent[u] = findRoot(parent[u]);
    }
    void unionH(int u, int v) {
        int pu = findRoot(u);
        int pv = findRoot(v);
        if(pu == pv) return;

        // if(height[pu] < height[pv]) parent[pu] = pv;
        // else if(height[pu] > height[pv]) parent[pv] = pu;
        // else {
        //     parent[pu] = pv;
        //     height[pv]++;
        // }
        parent[std::max(pu, pv)] = std::min(pu, pv); 
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        for(int i=0; i<s1.size(); i++) {
            dsu.unionH(s1[i] - 'a', s2[i] - 'a');
        }
        for(int i=0; i<baseStr.size(); i++) {
            baseStr[i] = dsu.findRoot(baseStr[i] - 'a') + 'a';
        }
        return baseStr;
    }
};