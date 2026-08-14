class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0 ;
        int r = 0;
        map<int,int>mp;
        int mx = 1;

        while(r < n){
         mp[s[r] - 'a']++;
         while(mp[s[r] - 'a'] > 2){
            mp[s[l] - 'a']--;
            l++;
          }
          mx = max(r - l + 1,mx);
          r++;
        }
        return mx;
    }
};