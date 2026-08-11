class Solution {
public:
    
    int lcs(string& s , string& t,vector<vector<int>>& dp,int i,int j){
        if(i < 0 || j < 0)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == t[j])
        return 1 + lcs(s,t,dp,i-1,j-1);
        else{
            return dp[i][j] = max(lcs(s,t,dp,i-1,j),lcs(s,t,dp,i,j-1));
        }
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        string t = s;
        reverse(t.begin(),t.end());

        return n - lcs(s,t,dp,n-1,n-1);
    }
};