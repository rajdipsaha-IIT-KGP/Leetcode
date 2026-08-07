class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>last(n,0);

        for(int i = 0 ; i < n ; i++){
            last[i] = i;
        }

        int mx = 0;
        int mxIndex = -1;
        
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < n ; i++){
         for(int j = 0 ; j < i ; j++){
            if((nums[i] % nums[j]) == 0 && (dp[i] < 1 + dp[j])){
              dp[i] = 1 + dp[j];
              last[i] = j;
            }
         }
         if(mx < dp[i]){
            mx = dp[i];
            mxIndex = i;
         }
        }

        stack<int>st;

        st.push(nums[mxIndex]);

        while(last[mxIndex] != mxIndex){
            st.push(nums[last[mxIndex]]);
            mxIndex = last[mxIndex];
        }

        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};