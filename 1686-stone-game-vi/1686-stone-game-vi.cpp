class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,int>>nums;
        int n = aliceValues.size();

        for(int i = 0 ; i < n ; i++){
            nums.push_back({aliceValues[i]+bobValues[i],i});
        }
        int ans = 0;
        int turn = 1; // alice

        sort(nums.rbegin(),nums.rend());

        for(int i = 0 ; i < n ;i++){
          if(turn == 1){
            ans += aliceValues[nums[i].second];
            turn = 0;
          } else {
            ans -= bobValues[nums[i].second];
            turn = 1;
          }
        }
        if(ans == 0)
        return 0;
        if(ans > 0)
        return 1;
        if(ans < 0)
        return -1;
        return 7;
    }
};