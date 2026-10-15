class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]);

                long long cnt = st.size();
                ans = (ans + cnt * cnt) % MOD;
            }
        }

        return ans;
    }
};