class Solution {
public:
    int f(vector<vector<int>>&dp,vector<int>& nums,int index,int amount){
        if(index == 0)
        {
            if(amount % nums[index] == 0)
            return amount / nums[index];
            return 1e9;
        }
        if(dp[index][amount] != -1)
        return dp[index][amount];

        int np = f(dp,nums,index - 1,amount);
        int p = 1e9;
        if(amount >= nums[index])
        p = 1 + f(dp,nums,index,amount - nums[index]);

        return dp[index][amount] = min(p,np);
    }
    int coinChange(vector<int>& nums, int amount) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(dp,nums,n-1,amount) >= 1e9 ? -1 : f(dp,nums,n-1,amount);
    }
};