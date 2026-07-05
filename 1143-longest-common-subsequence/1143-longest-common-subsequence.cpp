class Solution {
public:
    int f(vector<vector<int>>&dp,int i,int j,string &s1,string &s2){
        if(i < 0 || j < 0)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        if(s1[i] == s2[j])
        return dp[i][j] = 1+f(dp,i - 1,j - 1,s1,s2);
        
        return dp[i][j] = max(f(dp,i - 1,j,s1,s2),f(dp,i,j - 1,s1,s2));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(dp,n - 1,m - 1,s1,s2);
    }
};