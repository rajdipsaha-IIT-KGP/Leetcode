class Solution {
public:
    int f(vector<vector<int>>& dp,int i,int j,string s,string t){
        if(j < 0)
        return 1;
        if(i < 0)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == t[j]){
           return dp[i][j] = f(dp,i-1,j-1,s,t) + f(dp,i-1,j,s,t);
        }
        return dp[i][j] = f(dp,i-1,j,s,t);

    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n < m)
        return 0;

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(dp,n-1,m-1,s,t);

    }
};