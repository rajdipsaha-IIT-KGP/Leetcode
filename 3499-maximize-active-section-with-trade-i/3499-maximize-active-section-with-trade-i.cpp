class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt = 0;
        int ones = 0;

        vector<int>ans;

        for(int i = 0 ; i < n ;i++){
          if(s[i] == '0')
          cnt++;
          else{
            ones++;
            if(cnt != 0)
            ans.push_back(cnt);
            cnt = 0;
          }
        }
        if(cnt != 0)
        ans.push_back(cnt);

        int mx = 0;

        for(int i = 1 ; i < ans.size() ; i++){
            mx = max(mx,ans[i] + ans[i - 1]);
        }
        return mx == 0 ? ones :mx + ones;
    }
};