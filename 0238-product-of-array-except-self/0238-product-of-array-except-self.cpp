class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>prefix(n,1);
        vector<int>suffix(n,1);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for(int i = 1 ; i < n ;  i++){
          prefix[i] = prefix[i - 1] * nums[i];
          suffix[n - i - 1] = suffix[n - i] * nums[n - i - 1];
        }

        vector<int>ans;

        for(int i = 0 ;  i < n ; i++){
            if(i == 0)
            ans.push_back(suffix[i + 1]);
            else if(i == n - 1)
            ans.push_back(prefix[i - 1]);
            else ans.push_back(prefix[i - 1] * suffix[i + 1]);
        }

        return ans;
    }
};