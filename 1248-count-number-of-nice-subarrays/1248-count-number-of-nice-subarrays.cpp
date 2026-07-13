class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &it : nums){
            if(it % 2 == 0)
            it = 0; else {
                it = 1;
            }
        }

        map<int,int>mp;
        mp[0] = 1;

        int p = 0;
        int cnt = 0;

        for(auto it : nums){
            p += it;
            if(mp.find(p-k) != mp.end())
            cnt += mp[p - k];
            mp[p]++;
        }
        return cnt;
    }
};