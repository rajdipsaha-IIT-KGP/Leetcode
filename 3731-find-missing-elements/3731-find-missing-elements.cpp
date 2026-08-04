class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>freq(nums[n - 1] + 1, 0);

        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
        }
        vector<int>b;
        for(int i = nums[0] ;  i < freq.size() ; i++)
        {
            if(freq[i] == 0){
                b.push_back(i);
            }
        }
        return b;
    }
};