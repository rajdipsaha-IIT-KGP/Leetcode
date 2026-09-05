class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pmx(n,0);
        pmx[0] = nums[0];
        vector<int>smn(n,0);
        smn[n - 1] = nums[n - 1];


        for(int i = 1 ; i < n ; i++){
            pmx[i] = max(pmx[i - 1],nums[i]);
        }

        for(int i = n - 2 ; i >= 0 ; i--){
           smn[i] = min(smn[i + 1],nums[i]);
        }

        for(int i = 0 ; i < n ; i++){
            if((pmx[i] - smn[i]) <= k)
            return i;
        }
        return -1;
    }
};