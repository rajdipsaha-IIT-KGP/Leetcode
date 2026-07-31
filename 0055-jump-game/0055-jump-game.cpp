class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxIndex = 0;
        for(int i = 0 ; i < n ; i++){
          if(i > mxIndex)
          return false;
          mxIndex = max(mxIndex,nums[i] + i);
        }
        return true;
    }
};