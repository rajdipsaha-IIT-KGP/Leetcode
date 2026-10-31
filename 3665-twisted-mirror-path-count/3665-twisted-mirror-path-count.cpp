class Solution {
public:
 typedef long long ll;
    int MOD = 1e9 + 7;
    int n,m;
    int f(vector<vector<vector<int>>>& dp,vector<vector<int>>& grid,int i,int j,int left){
        if(i >= n || j >= m)
        return 0;
        if(i == n - 1 && j == m - 1)
        return 1;

        if(dp[i][j][left] != INT_MAX)
        return dp[i][j][left];


        ll ans = 0LL;

        if(grid[i][j] == 1){
          if(left == 1)
          return dp[i][j][left] = f(dp,grid,i+1,j,0);
          else return dp[i][j][left] = f(dp,grid,i,j+1,1);
        }
        return dp[i][j][left] = (f(dp,grid,i+1,j,0) + f(dp,grid,i,j+1,1)) % MOD;

    }
    int uniquePaths(vector<vector<int>>& grid) {

         n = grid.size();
         m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,INT_MAX)));
        return f(dp,grid,0,0,0);
    }
};