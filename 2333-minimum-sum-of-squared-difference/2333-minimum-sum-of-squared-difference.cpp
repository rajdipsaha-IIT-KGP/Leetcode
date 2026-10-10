class Solution {
public:
   typedef long long ll;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int>Frequency_Of_Differences_Between_Two_Array(1e5+1,0);
        for(int i = 0 ; i < n ; i++){
            Frequency_Of_Differences_Between_Two_Array[abs(nums1[i] - nums2[i])]++;
        }

        ll ans = 0LL;
        ll k = 1LL * (k1 + k2);

        for(int i = 1e5 ; i > 0 && k > 0 ; i--){
              ll countOps = min(1LL * Frequency_Of_Differences_Between_Two_Array[i],k);
              Frequency_Of_Differences_Between_Two_Array[i] -= countOps;
              Frequency_Of_Differences_Between_Two_Array[i - 1] += countOps;
              k -= countOps;
        } 
        for(int i = 0 ; i <= 1e5 ; i++){
            ans += 1LL * Frequency_Of_Differences_Between_Two_Array[i] * i * i;
        }
        return ans;
    }
};