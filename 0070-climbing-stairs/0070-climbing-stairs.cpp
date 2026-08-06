class Solution {
public:
  int f(vector<int>&dp,int n){
    if(n == 0)
    return 1;
    if(n < 0)
    return 0;
    if(dp[n] != -1)
    return dp[n];
    int first = f(dp,n - 1);
    int second = f(dp,n - 2);
    return dp[n] = first + second;
  }
    int climbStairs(int n) {
        vector<int>dp(n + 1,-1);
        return f(dp,n);
    }
};