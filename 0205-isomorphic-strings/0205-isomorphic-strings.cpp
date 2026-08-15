class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp;
        map<char,char>mp1;
        for(int i = 0 ; i < s.size() ; i++){
         if(mp.find(s[i]) != mp.end())
         {
            if(mp[s[i]] != t[i])
            return false;
         }
         else{
            mp[s[i]] = t[i];
         }
          if(mp1.find(t[i]) != mp1.end())
         {
            if(mp1[t[i]] != s[i])
            return false;
         }
         else{
            mp1[t[i]] = s[i];
         }

        }
        return true;
    }
};