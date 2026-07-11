class Solution {
public:
    class DisjointSet {
    public:
        vector<int> parent, size;

        DisjointSet(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findUltimateParent(int node) {
            if (parent[node] == node)
                return node;

            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionBySize(int u, int v) {
            int pu = findUltimateParent(u);
            int pv = findUltimateParent(v);

            if (pu == pv) return;

            if (size[pu] >= size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DisjointSet ds(n);

        
        for (auto &it : edges) {
            ds.unionBySize(it[0], it[1]);
        }

        
        unordered_map<int, int> vertices;

        for (int i = 0; i < n; i++) {
            int p = ds.findUltimateParent(i);
            vertices[p]++;
        }

        
        unordered_map<int, int> edgeCnt;

        for (auto &it : edges) {
            int p = ds.findUltimateParent(it[0]);
            edgeCnt[p]++;
        }

        int ans = 0;

        
        for (auto &it : vertices) {
            int parent = it.first;
            int v = it.second;
            int e = edgeCnt[parent];

            if (e == (v * (v - 1)) / 2)
                ans++;
        }

        return ans;
    }
};