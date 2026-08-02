class Solution {
public:
    int f(vector<vector<int>>& dp,vector<int>& piles,int i,int j){
        if(i > j)
        return 0;
        if (i == j)
        return piles[i];       

        if(dp[i][j] != -1)
        return dp[i][j];

        int take_i = piles[i] + min(f(dp,piles,i+2,j),f(dp,piles,i+1,j-1));
        int take_j = piles[j] + min(f(dp,piles,i+1,j-1),f(dp,piles,i,j-2));

        return dp[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
       int total = accumulate(piles.begin(),piles.end(),0LL);

        int p1 = f(dp,piles,0,n - 1);
        int p2 = total - p1;

        return p1 >= p2;
    }
};