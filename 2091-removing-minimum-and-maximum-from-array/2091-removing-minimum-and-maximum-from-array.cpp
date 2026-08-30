class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return 1;
        if(n < 4)
        return 2;

        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());

        int mxIndex = -1;
        int mnIndex = -1;

        for(int i = 0 ; i < n ; i++){
          if(nums[i] == mx){
            mxIndex = i;
          } 
          if(nums[i] == mn){
            mnIndex = i;
          }
        }

        int s = 0;
        int e = n - 1;

       int l = min(mxIndex,mnIndex);
       int r = max(mxIndex,mnIndex);

       int bothFront = r + 1;
       int bothBack = n - l;
       int bothEnd = (n - r) + (l + 1);


       return min({bothFront,bothBack,bothEnd});
    }
};