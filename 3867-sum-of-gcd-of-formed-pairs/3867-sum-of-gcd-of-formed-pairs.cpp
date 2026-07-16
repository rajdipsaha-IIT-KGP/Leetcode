class Solution {
public:
   typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];

        vector<int>prefixGCD;
        prefixGCD.push_back(mx);

        for(int i = 1 ; i < n ; i++){
            if(mx < nums[i])
            mx = nums[i];
          prefixGCD.push_back(gcd(nums[i],mx));
        }

        sort(prefixGCD.begin(),prefixGCD.end());

        int l = 0;
        int r = n - 1;

        ll cnt = 0LL;

        while(l < r){
          cnt += 1LL * gcd(prefixGCD[l],prefixGCD[r]);
          l++;
          r--;
        }

        return cnt;
    }
};