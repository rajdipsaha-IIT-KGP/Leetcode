class Solution {
public:
    
    vector<int>prev;
    int m = 1e9 + 7;
    
    int solve(int n,vector<int>& dp){
        if(n == 0)
        return 1;
        if(dp[n] != -1)
        return dp[n];

        int tot = (solve(n - 1,dp) * 2) % m;

       int dup = 0;
        if(prev[n] != 0)
         dup = solve(prev[n] - 1,dp);

        tot = ((tot - dup + m)) % m;
        return dp[n] = tot;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        prev.assign(n+1,0);
       
       vector<int>lastSeen(26,0);

        for(int i = 1 ; i <= n ;  i++){
           int index = s[i - 1] - 'a';
           prev[i] = lastSeen[index];
           lastSeen[index] = i;
        }

        vector<int>dp(n+1,-1);

        return (solve(n,dp) - 1 + m) % m;
    }
};