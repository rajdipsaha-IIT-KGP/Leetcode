class Solution {
public:
    int f(vector<vector<int>>&dp,string &s,string &t,int i,int j){
        if(i < 0 || j < 0)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        if(s[i] == t[j])
        return dp[i][j] = 1 + f(dp,s,t,i-1,j-1);
        return  dp[i][j] = max(f(dp,s,t,i-1,j),f(dp,s,t,i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());

        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
return f(dp,s,t,n-1,n-1);
    }
};