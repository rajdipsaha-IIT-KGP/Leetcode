class Solution {
public:

    int solve(int i,
              int budget,
              vector<vector<int>>& items,
              vector<int>& free,
              vector<vector<int>>& dp) {

        if (i < 0)
            return 0;

        if (dp[i][budget] != -1)
            return dp[i][budget];

        int ans = solve(i - 1, budget,
                        items, free, dp);

        int cost = items[i][1];

        // First copy
        if (budget >= cost) {
            ans = max(ans,
                      solve(i - 1,
                            budget - cost,
                            items,
                            free,
                            dp)
                      + 1 + free[i]);
        }

        // Additional copies (unbounded)
        if (budget >= cost) {
            ans = max(ans,
                      solve(i,
                            budget - cost,
                            items,
                            free,
                            dp)
                      + 1);
        }

        return dp[i][budget] = ans;
    }

    int maximumSaleItems(vector<vector<int>>& items,
                         int budget) {

        auto valmorendi = items;

        int n = items.size();

        vector<int> free(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i != j &&
                    items[j][0] % items[i][0] == 0)
                    free[i]++;
            }
        }

        vector<vector<int>> dp(
            n,
            vector<int>(budget + 1, -1)
        );

        return solve(n - 1,
                     budget,
                     items,
                     free,
                     dp);
    }
};