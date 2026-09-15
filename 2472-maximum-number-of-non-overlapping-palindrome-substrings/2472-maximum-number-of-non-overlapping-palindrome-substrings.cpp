class Solution {
public:
    bool isPallindrome(string& s,int i,int j){
        while(i <= j){
            if(s[i] != s[j])
            return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    int solve(vector<vector<int>>& dp,string& s,int i,int j,int n,int k){
      if(i >= n || j >= n)
      return 0;
      if(dp[i][j] != -1)
      return dp[i][j];

      if(isPallindrome(s,i,j)){
        int take = 1 + solve(dp,s,j+1,j+k,n,k);
        int grow = solve(dp,s,i,j+1,n,k);
        int slide = solve(dp,s,i+1,j+1,n,k);
        return dp[i][j] = max({take,grow,slide});
      } 
         int grow = solve(dp,s,i,j+1,n,k);
        int slide = solve(dp,s,i+1,j+1,n,k);
      return dp[i][j] = max(grow,slide);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1)
        return n;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(dp,s,0,k-1,n,k);
    }
};