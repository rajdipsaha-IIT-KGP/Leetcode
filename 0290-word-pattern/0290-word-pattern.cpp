class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        vector<string>a;
        string str = "";

       

        for(int i = 0 ; i < n ; i++){
          if(s[i] == ' '){
            if(str != ""){
              a.push_back(str);
            }
            str = "";
            continue;
          }
          str += s[i];
        }
        if (str != "") {
          a.push_back(str);
        }

        if (a.size() != pattern.size())
        return false;

        map<char,string>mp;
        map<string,char>mp1;

        for(int i = 0 ; i < pattern.size() ; i++){
          if(mp.find(pattern[i]) != mp.end()){
            if(mp[pattern[i]] != a[i])
            return false;
          } else {
            mp[pattern[i]] = a[i];
          }
        }
        for(int i = 0 ; i < pattern.size() ; i++){
          if(mp1.find(a[i]) != mp1.end()){
            if(mp1[a[i]] != pattern[i])
            return false;
          } else {
            mp1[a[i]] = pattern[i];
          }
        }
        return true;
    }
};