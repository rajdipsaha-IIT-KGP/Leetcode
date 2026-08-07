class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);

        int mx = INT_MIN;
       
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
              if(nums[i] > nums[j]){
                 if(dp[i] < 1 + dp[j]){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                 } else if(dp[i] == 1 + dp[j]){
                    cnt[i] += cnt[j];
                 }
              }
            }
            if(mx < dp[i]){
                mx = dp[i];
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
           if(dp[i] == mx){
            ans += cnt[i];
           }
        }
  
  return ans;

    }
};