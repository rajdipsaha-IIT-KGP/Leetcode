class Solution {
public:
typedef long long ll;
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll ans = 0LL;

        for(int i = 0 ; i < nums.size() ; i++){
            ans += (nums[i] - nums[0]) * 1LL;
        }
        return ans;
    }
};