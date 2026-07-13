class Solution {
public:
    int f(vector<int>& nums,vector<int>& dp,int index){
        if(index == nums.size() - 1)
        return 0;
        if(index >= nums.size())
        return 1e9;
        if(dp[index] != -1)
        return dp[index];

        int mn = 1e9;
        for(int i = 1 ; i <= nums[index] ; i++){
            mn = min(mn,1 + f(nums,dp,index + i));
        }
        return dp[index] = mn;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(nums,dp,0);
    }
};