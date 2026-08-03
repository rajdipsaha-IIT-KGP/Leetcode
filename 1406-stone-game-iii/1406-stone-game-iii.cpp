class Solution {
public:
   int f(vector<int>& dp,int index,vector<int>& stoneValue){
    if(index >= stoneValue.size())
    return 0;

    if(dp[index] != -1)
    return dp[index];
     
     int ans = -1e9;
     int sum = 0;
    for(int k = 0 ; k < 3 ; k++){
        if(index + k < stoneValue.size())
        sum += stoneValue[index + k];
        ans = max(ans,sum - f(dp,index + k + 1,stoneValue));
    }
    return dp[index] = ans;

   }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n,-1);
        int diff =  f(dp,0,stoneValue);
        if(diff == 0)
        return "Tie";
        else if(diff > 0)
        return "Alice";
        else return "Bob";
    }
};