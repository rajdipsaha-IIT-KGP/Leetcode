class Solution {
public:
    typedef long long ll;
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<ll>prefixSum(n,0);
        prefixSum[0] = stones[0];

        for(int i = 1 ; i < n ; i++){
           prefixSum[i] = 1LL*prefixSum[i - 1] + stones[i];
        }
     
      
        ll dp = prefixSum[n - 1];
      

        for(int i = n - 2 ; i >= 1 ; i--){
            dp = max(prefixSum[i] - dp,dp);
        }
        return dp;
    }
};