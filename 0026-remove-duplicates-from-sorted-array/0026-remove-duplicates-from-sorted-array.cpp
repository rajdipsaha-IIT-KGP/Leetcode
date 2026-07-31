class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
       
        vector<int>ans(st.begin(),st.end());
        nums = ans;
        return nums.size();
    }
};