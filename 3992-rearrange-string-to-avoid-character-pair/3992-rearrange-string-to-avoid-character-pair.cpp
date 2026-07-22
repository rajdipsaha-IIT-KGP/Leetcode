class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.size();
        map<char,int>mp;

        for(int i = 0 ; i < n ; i++){
          mp[s[i]]++;
        }

        string t = "";
        int c1 = mp[y];
        int c2 = mp[x];

        for(int i = 0 ; i < c1 ; i++){
            t += y;
        }

        for(int i = 0 ; i < c2 ; i++){
            t += x;
        }

        for(auto it : mp){
            if(it.first == x || it.first == y){
               continue;
            }
            for(int i = 0 ; i < it.second ; i++)
            t += it.first;
        }
        return t;
    }
};