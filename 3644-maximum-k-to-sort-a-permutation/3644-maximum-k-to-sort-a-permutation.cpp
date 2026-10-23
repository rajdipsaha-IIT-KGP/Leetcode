class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
       
       int res = INT_MAX;
       vector<int>cpy = nums;
       sort(cpy.begin(),cpy.end());
       if(cpy == nums)
       return 0;
        for(int i = 0 ; i < n ; i++){
          if(nums[i] != i)
          res &= nums[i];
        }
      return res;
    }
};