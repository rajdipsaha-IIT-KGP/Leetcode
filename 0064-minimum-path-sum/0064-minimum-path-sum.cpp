class Solution {
public: 
    int f(vector<vector<int>>& dp,vector<vector<int>>& grid,int row,int col,int m,int n){
      if(row == n - 1 && col == m - 1){
        return grid[row][col];
      }
      if(row >= n || col >= m)
      return 1e9;

      if(dp[row][col] != -1)
      return dp[row][col];

      int down = grid[row][col] + f(dp,grid,row + 1,col,m,n);
      int right = grid[row][col] + f(dp,grid,row,col + 1,m,n);

      return dp[row][col] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(dp,grid,0,0,m,n);

    }
};