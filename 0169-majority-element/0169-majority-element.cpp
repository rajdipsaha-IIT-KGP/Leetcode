class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int elem = -1;

        for(int i = 0 ; i < n ; i++){
            if(cnt == 0){
                elem = nums[i];
                cnt = 1;
            } else {
                if(nums[i] == elem)
                cnt++;
                else cnt--;
            }
        }

        return elem;
    }
};