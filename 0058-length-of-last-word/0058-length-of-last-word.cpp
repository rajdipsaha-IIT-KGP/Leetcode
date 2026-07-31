class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int l = n - 1;
        int r = 0;

        while(l >= 0 && s[l] == ' '){
          l--;
        }

        if(l < 0)
        return 0;

        r = l;

        if(l == 0)
        return 1;

        while(l >= 0 && s[l] != ' '){
            l--;
        }
        
        return r - (l + 1) + 1;

    }
};