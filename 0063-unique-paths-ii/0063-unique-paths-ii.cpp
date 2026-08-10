class Solution {
public:
    int f(vector<vector<int>>&dp,vector<vector<int>>&a,int row,int col){
        if(row == 0 && col == 0 && a[row][col] != 1)
        return 1;

        if(row < 0 || col < 0)
        return 0;

        if(a[row][col] == 1)
        return 0;

        if(dp[row][col] != -1)
        return dp[row][col];

        int up = f(dp,a,row-1,col);
        int left = f(dp,a,row,col - 1);
        return dp[row][col] = up + left;


    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int row = a.size();
        int col = a[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
       return f(dp,a,row-1,col-1);
    }
};