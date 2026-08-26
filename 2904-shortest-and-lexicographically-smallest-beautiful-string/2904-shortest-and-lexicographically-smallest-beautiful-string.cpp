class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int l = 0;
        int ones = 0;

        string ans = "";
        int bestLen = INT_MAX;

        for (int r = 0; r < n; r++) {

            if (s[r] == '1')
                ones++;

            while (ones == k) {

                int len = r - l + 1;
                string temp = s.substr(l, len);

                if (len < bestLen) {
                    bestLen = len;
                    ans = temp;
                }
                else if (len == bestLen && temp < ans) {
                    ans = temp;
                }

                if (s[l] == '1')
                    ones--;

                l++;
            }
        }

        return ans;
    }
};