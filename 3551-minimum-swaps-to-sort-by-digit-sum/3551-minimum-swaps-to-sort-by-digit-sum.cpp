class Solution {
public:
    int getDigitSum(int n){
      int sum = 0;

      while(n){
        sum += (n % 10);
        n /= 10;
      }
      return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int>cpy = nums;

        sort(cpy.begin(),cpy.end(),[&](int x,int y){
          if(getDigitSum(x) != getDigitSum(y))
          return getDigitSum(x) < getDigitSum(y);
          return x < y;
        });

       unordered_map<int,int>mp;

       for(int i = 0 ; i < n ; i++){
        mp[nums[i]] = i;
       }

       int swaps = 0;

       for(int i = 0 ; i < n ; i++){
        int eVal = cpy[i];
        int currVal = nums[i];
        if(eVal != currVal){
            swaps++;
         int idx1 = mp[eVal];
         int idx2 = mp[currVal];
         swap(nums[idx1],nums[idx2]);
         mp[eVal] = i;
         mp[currVal] = idx1;
        }
       }

       return swaps;

    }
};