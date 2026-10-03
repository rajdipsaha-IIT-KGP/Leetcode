class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        int open = 0;
        int close = 0;

        int result = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(')
            open++;
            else if(s[i] == ')')
            close++;
            if(open < close){
                close = 0;
                open = 0;
            } else if(close == open){
              result = max(open + close,result);
            }
        }

        close = 0;
        open = 0;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s[i] == '(')
            open++;
            else if(s[i] == ')')
            close++;
            if(open > close){
                close = 0;
                open = 0;
            } else if(close == open){
              result = max(open + close,result);
            }
        }
       return result;
    }
};