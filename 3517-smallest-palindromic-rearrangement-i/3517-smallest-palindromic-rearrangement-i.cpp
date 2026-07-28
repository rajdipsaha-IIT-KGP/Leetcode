class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>h(26,0);

        string str = s;
        for(int i = 0 ; i < n ; i++){
            str[i] = '$';
        }

        for(int i = 0 ; i < n ; i++){
            h[s[i] - 'a']++;
        }

        int cnt = 0;

        for(int i = 0 ; i < 26 ; i++){
         if(h[i] != 0){
            while(h[i] > 1){
             str[cnt] = (char)(i+'a');
             str[n - cnt - 1] = (char)(i+'a');
             cnt++;
             h[i] -= 2;
            }
         }
        }

        char ch = '$';

        for(int i = 0; i < 26 ;i ++){
           if(h[i] == 1){
            ch = i + 'a';
            break;
           }
        }
        if(ch == '$')
        return str;
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == '$')
            str[i] = ch;
        }
        return str;
    }
};
