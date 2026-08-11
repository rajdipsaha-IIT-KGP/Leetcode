class Solution {
public:
    int f(vector<vector<int>>& dp,string &s,string &t,int i,int j){
        if(i < 0 || j < 0)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == t[j])
        return dp[i][j] = 1 + f(dp,s,t,i-1,j-1);
       
        else{
            return dp[i][j] = max(f(dp,s,t,i-1,j),f(dp,s,t,i,j-1));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(dp,text1,text2,n-1,m-1);
    }
};