class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        unordered_set<int>a;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
             a.insert(nums[i] ^ nums[j]); 
            }
        }
        
        unordered_set<int>st;
        for(int i = 0 ; i < n ; i++){
            for(auto it : a)
             st.insert(it ^ nums[i]);
        }
        return st.size();
    }
};