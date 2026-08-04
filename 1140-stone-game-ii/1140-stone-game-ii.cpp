class Solution {
public:
int n;
   int f(vector<int>& piles,int index,int m,int turn,vector<vector<vector<int>>>&dp){
    if(index >= n){
        return 0;
    }
    int result = turn == 0 ? INT_MAX : -1;
    int stones = 0;
    
    if(dp[index][m][turn] != -1)
    return dp[index][m][turn];
    for(int x = 1 ; x <= min(2*m,n-index) ;x++){
        stones += piles[index+x-1];
        if(turn == 1){
            result = max(result,stones + f(piles,index + x,max(x,m),0,dp));
        } else {
            result = min(result,f(piles,index + x,max(x,m),1,dp));
        }
    }
    return dp[index][m][turn] = result;
   }
    int stoneGameII(vector<int>& piles) {
       n  = piles.size();
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
       return f(piles,0,1,1,dp);

    }
};