class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int mxp = -1;
        int mnp = -1;
        int ci = -1;

        ll cnt = 0LL;

        for(int i = 0 ; i < n ; i++){
           if(minK == nums[i])
           mnp = i;
           if(maxK == nums[i])
           mxp = i;

           if(nums[i] < minK || nums[i] > maxK)
           ci = i;
          
          if(mnp != -1 && mxp != -1)
          cnt += 1LL*(1LL*max(1LL*min(mxp,mnp) - ci,0LL));
           
        }
        return cnt;
    }
};