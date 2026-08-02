class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
         
        int low = 0;
        int high = n - 1;

        int idx = 0;
        int elem = INT_MIN;
        int ans = 0;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < nums[mid + 1]){
                ans = low;
                low = mid + 1;
            }
            else{
                
                high = mid;
            }
        }

        return low;
    }
};