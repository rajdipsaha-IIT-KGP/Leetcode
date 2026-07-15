class Solution {
public:
    vector<int>buildLPSArray(string s){
        int n = s.size();
        vector<int>lps(n,0);

        int i = 1; 
        int j = 0;

        while(i < n){
            if(s[i] == s[j]){
                lps[i] = j + 1;
                i++;
                j++;
            } else {
                while(j > 0 && s[i] != s[j]){
                    j = lps[j - 1];
                }
                if(s[i] == s[j]){
                    lps[i] = j + 1;
                    j++;
                }
                i++;
            }
        }
        return lps;
    }
    int KMP(string s){
        vector<int>lps = buildLPSArray(s);
        return lps[s.size() - 1];
    }
    string longestPrefix(string s) {
       return s.substr(0,KMP(s));
    }
};