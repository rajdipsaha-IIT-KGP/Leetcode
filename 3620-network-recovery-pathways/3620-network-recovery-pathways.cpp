class Solution {
public:
    bool isPossible(vector<vector<pair<int,int>>> &adj, int mnCost, long long k) {

        int n = adj.size();

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {

            auto [distance, node] = pq.top();
            pq.pop();

            if (distance > dist[node])
                continue;

            if (distance > k)
                return false;

            if (node == n - 1)
                return true;

            for (auto [neighbour, wt] : adj[node]) {

                if (wt < mnCost)
                    continue;

                if (dist[neighbour] > distance + wt) {
                    dist[neighbour] = distance + wt;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);

        int low = INT_MAX;
        int high = 0;

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (!online[u] || !online[v])
                continue;

            adj[u].push_back({v, w});

            low = min(low, w);
            high = max(high, w);
        }

        if (low == INT_MAX)
            return -1;

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(adj, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};