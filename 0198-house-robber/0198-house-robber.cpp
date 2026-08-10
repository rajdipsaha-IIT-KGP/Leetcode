class Solution {
public:
    int f(vector<int>& dp,int index,int n,vector<int>& nums){
        if(index >= n)
        return 0;

        if(dp[index] != -1)
         return dp[index];


        int op1 = nums[index] + f(dp,index + 2,n,nums);
        int op2 = 0 + f(dp,index + 1,n,nums);

        return dp[index] = max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,-1);
        return f(dp,0,n,nums);
    }
};