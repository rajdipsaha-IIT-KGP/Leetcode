class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int mx = 1;

        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < i ;j++){
                if(nums[i] > nums[j])
                dp[i] = max(1 + dp[j],dp[i]);
            }
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};