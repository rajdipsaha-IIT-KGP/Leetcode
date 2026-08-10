class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        int cnt = 0;
        vector<int>bitWise(32,0);
        int mn = INT_MAX;

        while(r < n){
            cnt |= nums[r];

            for(int pos = 0 ; pos < 32 ; pos++){
                if(nums[r] & (1 << pos)){
                 bitWise[pos]++;
                }
            } 
            while(l <= r && cnt >= k){
                for(int pos = 0 ; pos < 32 ; pos++){
                if(nums[l] & (1 << pos)){
                 bitWise[pos]--;
                }
                if(bitWise[pos] == 0){
                    cnt = cnt & (~(1 << pos));
                }
              }
              mn = min(r - l + 1,mn);
              l++;
            }
            r++;
        }
        return mn == INT_MAX ? -1 : mn;
    }
};