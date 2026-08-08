class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
      
        vector<int>nums(n+1,0);

        for(int i = 0 ; i <= n ; i++){
            int l = max(0,i - ranges[i]);
            int r = min(n,i + ranges[i]);
           nums[l] = max(nums[l],r);
        }

       

        int maxEnd = 0;
        int currEnd = 0;
        int taps = 0;

        for(int i = 0 ; i <= n ;i++){
            if(maxEnd < i)
            return -1;
            if(i > currEnd){
                taps++;
                currEnd = maxEnd;
            }
            maxEnd = max(maxEnd,nums[i]);
        }

        return taps;
    }
};