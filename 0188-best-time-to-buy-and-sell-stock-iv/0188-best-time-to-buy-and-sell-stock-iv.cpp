class Solution {
public: 
    int f(vector<int>& prices,vector<vector<vector<int>>>& dp,int index,int cap,int canBuyStock){
       if(index == prices.size() || cap == 0){
          return 0;
       }
       if(dp[index][cap][canBuyStock] != -1)
       return dp[index][cap][canBuyStock];
        int profit = 0;

       if(canBuyStock == 1){
          profit = max(-prices[index] + f(prices,dp,index+1,cap,0),f(prices,dp,index+1,cap,1));
       } else {
          profit = max(prices[index] + f(prices,dp,index+1,cap-1,1),f(prices,dp,index+1,cap,0));
       }
       return dp[index][cap][canBuyStock] = profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return f(prices,dp,0,k,1);
    }
};