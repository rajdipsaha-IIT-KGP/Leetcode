class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
         int n = nums.size();

         vector<pair<int,int>>a;
         if(nums.empty())
         return {};

         for(int i = 0 ; i < n ; i++){
            a.push_back({nums[i],i});
         }
         sort(a.begin(),a.end());
         int cnt = 1;
          vector<int>ans(n,0);
           
           ans[a[0].second] = cnt;
         for(int i = 1 ; i < n ; i++){
            if(a[i].first > a[i - 1].first){
                cnt++;
                ans[a[i].second] = cnt;
            } else {
                ans[a[i].second] = cnt;
            }
         }
         return ans;
    } 
};