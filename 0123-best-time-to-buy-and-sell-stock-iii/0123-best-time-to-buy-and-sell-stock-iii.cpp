class Solution {
public:
    int f(vector<vector<vector<int>>>& dp,
          vector<int>& prices,
          int index,
          int cap,
          int canBuy) {

        if(index == prices.size() || cap == 0)
            return 0;

        if(dp[index][cap][canBuy] != -1)
            return dp[index][cap][canBuy];

        int profit;

        if(canBuy) {
            profit = max(
                -prices[index] + f(dp, prices, index + 1, cap, 0),
                f(dp, prices, index + 1, cap, 1)
            );
        }
        else {
            profit = max(
                prices[index] + f(dp, prices, index + 1, cap - 1, 1),
                f(dp, prices, index + 1, cap, 0)
            );
        }

        return dp[index][cap][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(3, vector<int>(2, -1))
        );

        return f(dp, prices, 0, 2, 1);
    }
};