class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> prefixSum(n + 1, 0);
        deque<int> dq;

        int mn = INT_MAX;

        for(int j = 0; j <= n; j++) {

            if(j > 0) {
                prefixSum[j] = prefixSum[j - 1] + nums[j - 1];
            }

           
            while(!dq.empty() &&
                  prefixSum[dq.back()] >= prefixSum[j]) {
                dq.pop_back();
            }

            
            while(!dq.empty() &&
                  prefixSum[j] - prefixSum[dq.front()] >= k) {

                mn = min(mn, j - dq.front());

                dq.pop_front();
            }

            dq.push_back(j);
        }

        return mn == INT_MAX ? -1 : mn;
    }
};