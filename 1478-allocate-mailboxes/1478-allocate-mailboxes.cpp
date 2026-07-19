class Solution {
public:
    int calculateCost(vector<int>& storeLocations,int start,int end){
         
         int mid = start + ((end - start) / 2);
         int x = storeLocations[mid];

         int cost = 0;

         for(int i = start ; i <= end ; i++){
            cost += abs(x - storeLocations[i]);
         }
         return cost;
    }
    int f(vector<vector<int>>& dp,vector<int>& storeLocations,int index,int k,int n){
        if(index == n)
        return 0;
        if(k == 0)
        return 1e9;
        if(dp[index][k] != -1)
        return dp[index][k];
        
        int ans = 1e9;
        for(int end = index ; end < n ; end++){
           ans = min(ans,calculateCost(storeLocations,index,end) + f(dp,storeLocations,end + 1,k - 1,n));
        }
       return dp[index][k] = ans;
    }
    int minDistance(vector<int>& storeLocations, int k) {
         int n = storeLocations.size();
        vector<vector<int>>dp(n+1,vector<int>(k + 1,-1));
        sort(storeLocations.begin(),storeLocations.end());

        
        return f(dp,storeLocations,0,k,n);
    }
};