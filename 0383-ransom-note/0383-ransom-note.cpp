class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>h1(26,0);
        vector<int>h2(26,0);

        for(int i = 0 ; i < ransomNote.size() ; i++){
          h1[ransomNote[i]- 'a']++;
        }

        for(int i = 0 ; i < magazine.size() ; i++){
          h2[magazine[i]- 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++){
          if(h1[i] > h2[i])
          return false;
        }

        return true;

    }
};