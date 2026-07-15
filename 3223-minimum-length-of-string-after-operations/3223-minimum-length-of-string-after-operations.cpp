class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        map<char,int>mp;
        for(int i = 0 ; i < n ; i ++){
           mp[s[i]]++;
        }

        int cnt = 0;
        for(auto it : mp){
            if(it.second > 2){
              if(it.second % 2 != 0)
              cnt++; else cnt += 2;
            } else {
                cnt += it.second;
            }
        }
        return cnt;
    }
};