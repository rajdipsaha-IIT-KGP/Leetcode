class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        map<int,string>mp;

        int cnt = 1;
        int direction = 0; // 0 means forward 1 means backward

        for(int i = 0 ; i < n ; i++){
            if(direction == 0){
                mp[cnt].push_back(s[i]);
                cnt++;
                if(cnt == numRows){
                    direction = 1;
                }
            } else {
                mp[cnt].push_back(s[i]);
                cnt--;
                if(cnt == 1)
                direction = 0;
            }
        }
        string ans = "";
      for(auto it : mp){
         ans += it.second;
      }
      return ans;
    }
};