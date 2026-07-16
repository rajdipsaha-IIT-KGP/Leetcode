class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if(n != m){
            return false;
        }

        vector<int>hash1(26,0);
        vector<int>hash2(26,0);

        for(int i = 0 ; i < n ; i++){
            hash1[word1[i] - 'a']++;
            hash2[word2[i] - 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++){
            if((hash1[i] != 0 && hash2[i] == 0) || (hash1[i] == 0 && hash2[i] != 0)){
               return false;
            }
        }

        map<int,int>mp1;
        map<int,int>mp2;

        for(int i = 0 ; i < 26 ; i++){
             mp1[hash1[i]]++;
             mp2[hash2[i]]++;
        }

        return mp1 == mp2;
    }
};