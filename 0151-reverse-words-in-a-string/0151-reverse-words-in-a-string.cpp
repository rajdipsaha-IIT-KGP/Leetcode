class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());

      int i = 0, j = 0;

     while (j < n) {

    while (j < n && s[j] == ' ')
        j++;

    if (j == n) break;

    int st = i;

    while (j < n && s[j] != ' ')
        s[i++] = s[j++];

    reverse(s.begin() + st, s.begin() + i);

    while (j < n && s[j] == ' ')
        j++;

    if (j < n)
        s[i++] = ' ';
}

return s.substr(0, i);
 }
};