class Solution {
public:
    int f(vector<int>& prices, vector<vector<int>>& dp, int index, int buy, int fee) {
        if (index == prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        if (buy) {
            return dp[index][buy] = max(
                -prices[index] + f(prices, dp, index + 1, 0, fee),
                f(prices, dp, index + 1, 1, fee)
            );
        }

        return dp[index][buy] = max(
            prices[index] - fee + f(prices, dp, index + 1, 1, fee),
            f(prices, dp, index + 1, 0, fee)
        );
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, dp, 0, 1, fee);
    }
};