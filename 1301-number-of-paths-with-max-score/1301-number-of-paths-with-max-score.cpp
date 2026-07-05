class Solution {
public:
    const int MOD = 1e9 + 7;
    int f(vector<vector<int>>& dp,vector<string>& grid,int i,int j,int n,int m){
        if(i < 0 || j < 0)
        return -1e7;
       if(i == 0 && j == 0){
          return 0;
       }
       if(dp[i][j] != -1)
       return dp[i][j];

       int moveUp = -1e7;
       int moveLeft = -1e7;
       int moveUpLeft = -1e7;
       
       if(j > 0 && grid[i][j-1] != 'X'){
          moveLeft = (grid[i][j] != 'S' ? (grid[i][j] - '0') : 0) + f(dp,grid,i,j-1,n,m);
       }

       if(i > 0 && j > 0 && grid[i-1][j-1] != 'X'){
          moveUpLeft = (grid[i][j] != 'S' ? (grid[i][j] - '0') : 0) + f(dp,grid,i-1,j-1,n,m);
       }
       
       if(i > 0 && grid[i-1][j] != 'X'){
          moveUp = (grid[i][j] != 'S' ? (grid[i][j] - '0') : 0) + f(dp,grid,i-1,j,n,m);
       }

       return dp[i][j] = max({moveUp,moveLeft,moveUpLeft});
       
    }


    vector<int> pathsWithMaxScore(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1e7));
        vector<vector<int>>ways(n,vector<int>(m,0));
        dp[0][0] = 0;

        
        int mxPathSum = 0;

        ways[0][0] = 1;

        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                
                int cnt = 0;
                if(grid[i][j] == 'X' || (i == 0 && j == 0))
                continue;
                int val = 0;
                if(grid[i][j] >= '1' && grid[i][j] <= '9'){
                    val = grid[i][j] - '0';
                }
                int moveUp = -1e7;
                int moveLeft = -1e7;
                int moveUpLeft = -1e7;
                
                if (j > 0 && dp[i][j-1] != -1e7){
                    moveLeft = val + dp[i][j-1];
                    if(dp[i][j] < moveLeft){
                        dp[i][j] = moveLeft;
                        cnt = ways[i][j - 1];
                    }
                    else if(dp[i][j] == moveLeft){
                       cnt = (cnt + ways[i][j - 1]) % MOD;
                    }
                }
                    

                if (i > 0 && dp[i-1][j] != -1e7){
                    moveUp = val + dp[i-1][j];
                   if(dp[i][j] < moveUp){
                      dp[i][j] = moveUp;
                      cnt = ways[i-1][j];
                   }
                    else if(dp[i][j] == moveUp){
                       cnt = (cnt + ways[i-1][j]) % MOD;
                    } 
                } 
                
                if (i > 0 && j > 0 && dp[i-1][j-1] != -1e7){
                    moveUpLeft = val + dp[i-1][j-1];
                   if(dp[i][j] < moveUpLeft){
                      dp[i][j] = moveUpLeft;
                      cnt = ways[i-1][j-1];
                   }
                    else if(dp[i][j] == moveUpLeft){
                       cnt = (cnt + ways[i-1][j-1]) % MOD;
                    } 
                }
                ways[i][j] = cnt;
            }
        }

        if(ways[n-1][m-1] == 0){
            return {0,0};
        }
        return {max(mxPathSum,dp[n-1][m-1]),ways[n-1][m-1]};
        
    }
};