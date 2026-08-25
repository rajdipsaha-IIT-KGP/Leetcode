class Solution {
public:
  typedef long long ll;
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());

        ll x = k;

        while(st.find(x) != st.end()){
            x = x+k;
        }
        return x;
    }
};