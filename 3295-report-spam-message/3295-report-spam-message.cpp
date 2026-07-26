class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,int>mp;

        for(int i = 0 ; i < message.size() ; i++){
            mp[message[i]]++;
        }

        int cnt = 0;
        set<string>st(bannedWords.begin(),bannedWords.end());
        

        bannedWords.clear();
        for(auto &it : st){
          bannedWords.push_back(it);
        }
        for(int i = 0 ; i < bannedWords.size() ; i++){
            if(mp.find(bannedWords[i]) != mp.end())
            cnt += mp[bannedWords[i]];
        }
        return cnt >= 2;
    }
};