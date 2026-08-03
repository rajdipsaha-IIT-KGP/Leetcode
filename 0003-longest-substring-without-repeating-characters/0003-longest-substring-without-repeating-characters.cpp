class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char,int>mp;

        int l = 0;
        int r = 0;

        int mn = INT_MIN;

        while(r < n){
            if(mp.find(s[r]) != mp.end()){
                 if(mp[s[r]] >= l){
                    l = mp[s[r]] + 1;
                 }
            }
            mp[s[r]] = r;
          mn = max(r - l + 1,mn);
          r++;
        }
        return max(mn,0);
    }
};