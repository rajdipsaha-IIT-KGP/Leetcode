class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i = 0 ; i < n ; i++){
            dp[i][0] = grid[i][0]-'0';
        }

        for(int j = 0 ; j < m ; j++){
            dp[0][j] = grid[0][j]-'0';
        }


        for(int i = 1 ; i < n ;i++){
            for(int j = 1 ; j < m ; j++){
                if(grid[i][j]-'0' == 0){
                   dp[i][j] = 0;
                } else {
                     dp[i][j] = 1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }  
            }
        }

        int mx = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
             mx = max(mx,dp[i][j]);
            }
        }
        return mx*mx;
    }
};