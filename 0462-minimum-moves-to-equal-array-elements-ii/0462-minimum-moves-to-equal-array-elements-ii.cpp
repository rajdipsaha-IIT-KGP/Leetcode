class Solution {
public:
   typedef long long ll;
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int md = 0;
        if((n & 1) == 1)
        md = nums[n / 2];
        else md = (nums[n / 2] + nums[n / 2 - 1]) / 2;

        ll ans = 0LL;

        for(int i = 0 ; i < n ; i++){
         ans += abs(md - nums[i])*1LL;
        }
        return ans;
    }
};