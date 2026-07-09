class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int id = 0;
        vector<int>compid(n,0);
        for(int i = 1; i < n ; i++){
          if(nums[i] - nums[i - 1] > maxDiff){
            id++;
            compid[i] = id;
          }
          else{
            compid[i] = id;
          }
        }

      vector<bool>ans;

        for(int i = 0 ; i < queries.size(); i++){
             ans.push_back(compid[queries[i][0]] == compid[queries[i][1]]);
        }
        return ans;
    }
};