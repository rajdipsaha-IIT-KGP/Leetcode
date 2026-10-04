
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int open = 0;
        int close = 0;
        int stars = 0;

        // Left to right
        for(int i = 0; i < n; i++) {

            if(s[i] == '(') {
                open++;
            }
            else if(s[i] == ')') {
                close++;
            }
            else {
                stars++;
            }

            if(close > open) {
                if(close - open > stars) {
                    return false;
                }
                else {
                    stars -= (close - open);
                    close = 0;
                    open = 0;
                }
            }
        }

        // Right to left
        open = 0;
        close = 0;
        stars = 0;

        for(int i = n-1; i >= 0; i--) {

            if(s[i] == ')') {
                close++;
            }
            else if(s[i] == '(') {
                open++;
            }
            else {
                stars++;
            }

            if(open > close) {
                if(open - close > stars) {
                    return false;
                }
                else {
                    stars -= (open - close);
                    open = 0;
                    close = 0;
                }
            }
        }

        return true;
    }
};
