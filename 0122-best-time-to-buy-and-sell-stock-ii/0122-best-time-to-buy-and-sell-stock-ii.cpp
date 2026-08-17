class Solution {
public:

    int f(vector<int>& prices,vector<vector<int>>& dp,int buy,int index){
        if(index == prices.size())
        return 0;
        if(dp[index][buy] != -1)
        return dp[index][buy];

        int profit = 0;

        if(buy == 1) // we can buy the stock
        { 
           profit = max(-prices[index] + f(prices,dp,0,index+1),f(prices,dp,1,index+1));
        } else {
            profit = max(prices[index] + f(prices,dp,1,index+1),f(prices,dp,0,index+1));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

          dp[n][0] = 0;
          dp[n][1] = 0;

          vector<int>ahead(2,0);
          vector<int>curr(2,0);
        for(int index = n - 1 ; index >= 0 ; index--){
            int profit = 0;
            for(int buy = 1 ; buy >= 0 ; buy --){
                if(buy == 1) // we can buy the stock
        { 
           profit = max(-prices[index] + ahead[0],ahead[1]);
        } else {
            profit = max(prices[index] + ahead[1],ahead[0]);
        } 
          curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];


    }
};