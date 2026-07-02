class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int index = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] <= target){
               
               index = mid;
                low = mid + 1;
            }
            else{
                
                high = mid - 1;
            }

        }
        if(index == -1)
        return 0;
        if(nums[index] == target)
        return index;
        return index + 1;
    }
};