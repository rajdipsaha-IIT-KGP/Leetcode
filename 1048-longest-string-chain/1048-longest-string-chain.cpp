class Solution {
public:

    bool isPossible(string s,string t){
        int i = 0;
        int j = 0;
        
        if(s.size() - t.size() != 1)
        return false;

        while(i < s.size()){
            if(j < t.size() && s[i] == t[j]){
                j++;
            }
            i++;
        }
       
       return i == s.size() && j == t.size();

    }
    int longestStrChain(vector<string>& words) {

        int n = words.size();

        sort(words.begin(),words.end(),[](string &s,string &t){
            return s.size() < t.size();
        });

        vector<int>dp(n,1);
        int mx = 1;

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(isPossible(words[i],words[j])){
                    dp[i] = max(1 + dp[j] , dp[i]);
                }
            }
            mx = max(mx,dp[i]);
        }

      return mx;
       

    }
};