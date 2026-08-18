class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>hash(51,0);
        for(int i = 0 ; i < n ; i++){
                 hash[nums[i]]++;
            }
        if(k == n){
            return *max_element(nums.begin(),nums.end());
        }
        if(k == 1){
            
            int mx = -1;
            for(int i = 0 ; i < 51 ; i++){
                if(hash[i] == 1){
                    mx = max(mx,i);
                }
            }
            return mx;
        }
        
       if(hash[nums[0]] == 1 && hash[nums[n-1]] == 1){
         return max(nums[0],nums[n-1]);
       }
       if(hash[nums[0]] != 1 && hash[nums[n-1]] == 1){
          return nums[n-1];
       }
       if(hash[nums[0]] == 1 && hash[nums[n-1]] != 1){
        return nums[0];
       }
       return -1;

    }
};