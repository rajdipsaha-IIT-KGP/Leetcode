class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool allzeros = true;
        for(int i = 0 ; i < n ; i++){
          xr = xr ^ nums[i];
          if(nums[i] != 0)
          allzeros = false;
        }
        if(xr != 0)
        return n;
        if(!allzeros)
        return n - 1;
        return 0;
    }
};