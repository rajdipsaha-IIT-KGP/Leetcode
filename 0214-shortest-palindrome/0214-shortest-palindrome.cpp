class Solution {
public:
    
    vector<int>buildLPSArray(string s){
        int n = s.size();
       vector<int>lps(n,0);

       int j = 0 ;
       int i = 1;

       while(i < n){
        if(s[i] == s[j]){
            lps[i] = j + 1;
            j++;
            i++;
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

    int KMP(string& rev,string& s){
       string str = s + '$' + rev;
       vector<int>lps = buildLPSArray(str);
       int x = lps[str.size() - 1];
       return x;
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        int n = s.size();
        s = rev.substr(0,n-KMP(rev,s)) + s;
       return s;
    }
};