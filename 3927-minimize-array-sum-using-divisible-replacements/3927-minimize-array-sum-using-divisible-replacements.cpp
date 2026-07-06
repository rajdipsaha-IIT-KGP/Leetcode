class Solution {
public:
   typedef long long ll;
    long long minArraySum(vector<int>& nums) {

        int n = nums.size();

        int mx = *max_element(nums.begin(),nums.end());
        vector<int>freq(mx + 1,0);

        for(auto it : nums)
        freq[it]++;

        ll ans = 0LL;

        for(int i = 0 ; i < n ; i ++){
            int elem = nums[i];
         for (int k = 1; k * k <= nums[i]; k++) {
    if (nums[i] % k)   
        continue;

    if (freq[k])
        elem = min(elem, k);  

    int another = nums[i] / k;
    if (freq[another])
        elem = min(elem, another);
}
            ans += 1LL*elem;
        }
        return ans;
    }
};