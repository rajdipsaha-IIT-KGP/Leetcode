class Solution {
public:
    static constexpr int M = 1e9 + 7;

    int n, cols;
    vector<vector<int>> adj;
    vector<vector<int>> ancestorTable;
    vector<int> depth;

    void dfs(int node, int parent) {
        ancestorTable[node][0] = parent;

        for (int nxt : adj[node]) {
            if (nxt == parent) continue;

            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                int p = ancestorTable[node][j - 1];
                if (p != -1)
                    ancestorTable[node][j] = ancestorTable[p][j - 1];
            }
        }
    }

    int findLCA(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int k = depth[u] - depth[v];

        for (int j = 0; j < cols; j++) {
            if (k & (1 << j))
                u = ancestorTable[u][j];
        }

        if (u == v)
            return u;

        for (int j = cols - 1; j >= 0; j--) {
            if (ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        n = edges.size() + 1;

        cols = 1;
        while ((1 << cols) <= n)
            cols++;

        adj.assign(n, {});
        depth.assign(n, 0);
        ancestorTable.assign(n, vector<int>(cols, -1));

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth[0] = 0;
        dfs(0, -1);
        buildAncestorTable();

        vector<int> pow2(n + 1);
        pow2[0] = 1;

        for (int i = 1; i <= n; i++)
            pow2[i] = (2LL * pow2[i - 1]) % M;

        vector<int> result;

        for (auto &q : queries) {
            int u = q[0] - 1;
            int v = q[1] - 1;

            int lca = findLCA(u, v);

            int d = depth[u] + depth[v] - 2 * depth[lca];

            if (d == 0)
                result.push_back(0);
            else
                result.push_back(pow2[d - 1]);
        }

        return result;
    }
};