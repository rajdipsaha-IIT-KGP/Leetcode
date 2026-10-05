class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        int depth = 0;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(')
            depth++;
            else {
                depth--;
                if(s[i - 1] == '('){
                    ans += (1 << depth);
                }
            }
        }
        return ans;
    }
};