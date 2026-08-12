class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;

        int l = 0 ;
        int r = 0 ;
        int mx = INT_MIN;
         
        while(r < n){
           mp[nums[r]]++;
           if(mp.find(nums[r]) != mp.end()){
               while(l <= r && mp[nums[r]] > k){
                 mp[nums[l]]--;
                 l++;
               }
           }
           mx = max(mx,r-l+1);
           r++;
        }
        return mx;
    }
};