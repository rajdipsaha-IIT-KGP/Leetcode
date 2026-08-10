class Solution {
public:
   int f(vector<int>& dp,string &s,unordered_map<string,int>& mp,int index){
     if(index >= s.size())
     return true;

     if(dp[index] != -1)
     return dp[index];
     
     for(int i = index ; i < s.size() ; i++){
        string word = s.substr(index,i - index + 1);
        if(mp.find(word) != mp.end()){
            if(f(dp,s,mp,i+1))
            return dp[index] = true;
        }
     }
     return dp[index] = false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string,int>mp;
        for(auto it : wordDict){
            mp[it]++;
        }
        vector<int>dp(n,-1);
        return f(dp,s,mp,0);
    }
};