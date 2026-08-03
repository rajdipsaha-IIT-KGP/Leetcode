class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        int mn = INT_MAX;
        int sum = 0;

        while(r < n){
           sum += nums[r];
           while(sum >= target){
            sum -= nums[l];
            mn = min(mn,r - l + 1);
            l++;
           }
           r++;
        }
        return mn == INT_MAX ? 0 : mn;
    }
};