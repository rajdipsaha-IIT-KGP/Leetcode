class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int>cpy = nums;
        sort(cpy.begin(),cpy.end());

        unordered_map<int,list<int>>makeGroup;
        unordered_map<int,int>getGroupnoFromNum;

        int gn = 0;

        makeGroup[gn].push_back(cpy[0]);
        vector<int>ans;

        for(int i = 1 ; i < n ; i++){
            if(cpy[i] - cpy[i - 1] > limit){
                gn++;
            }
            getGroupnoFromNum[cpy[i]] = gn;
            makeGroup[gn].push_back(cpy[i]);
        }

        for(int i = 0 ; i < n ; i++){
             int groupNum = getGroupnoFromNum[nums[i]];
             ans.push_back(*(makeGroup[groupNum].begin()));
             makeGroup[groupNum].pop_front();
        }
        return ans;
    }
};