class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();

        vector<int>nums1(n,1);
        vector<int>nums2(n,1);

        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i - 1]){
                nums1[i] = nums1[i - 1] + 1;
            }
        }

      for(int i = n-2; i >= 0; i--){
    if(nums[i] > nums[i+1])
        nums2[i] = nums2[i+1] + 1;
}
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            ans += max(nums1[i],nums2[i]);
        }

        return ans;

    }
};