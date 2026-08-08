class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int cnt = 0;

        vector<int>nums;

        for(int i = 0 ; i < n ; i++){
            if(capacity[i] != rocks[i]){
               nums.push_back(capacity[i] - rocks[i]);
            } else {
                cnt++;
            }
        }

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            if(additionalRocks == 0)
            break;
            else {
                if(additionalRocks >= nums[i]){
                    cnt++;
                    additionalRocks -= nums[i];
                }
            }
        }

        return cnt;
    }
};