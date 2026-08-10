class Solution {
public:
    int f(vector<vector<int>>& dp,vector<vector<int>>& triangle,int row,int col,int n){
        if(row == n - 1)
        return triangle[row][col];

        if(dp[row][col] != 1e9)
        return dp[row][col];
        
        int down = triangle[row][col] + f(dp,triangle,row+1,col,n);
        int diagonal = triangle[row][col] + f(dp,triangle,row+1,col+1,n);

        return dp[row][col] = min(down,diagonal);

        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        
        return f(dp,triangle,0,0,n);
    }
};