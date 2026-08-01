class Solution {
public:
   int f(vector<vector<int>>& dp,vector<int>& nums,int i,int j){
     if(i >= nums.size() || j < 0)
     return 0;
      if(i > j)
      return 0;
      if(i == j)
      return nums[i];
      int take_i = nums[i] + min(f(dp,nums,i+2,j),f(dp,nums,i+1,j-1));
      int take_j = nums[j] + min(f(dp,nums,i+1,j-1),f(dp,nums,i,j-2));

      return dp[i][j] = max(take_i,take_j);
   }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int tot = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int p1 = f(dp,nums,0,n-1);
        int p2 = tot - p1;

        return p1 >= p2;
    }
};