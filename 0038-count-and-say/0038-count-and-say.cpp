class Solution {
public:
    string returnRLE(string &s,int cnt,int n){
        if(cnt > n)
        return "";
      return s = s + to_string(cnt) + '1' + returnRLE(s,cnt+1,n);
    }
    string countAndSay(int n) {
        string s = "1";
        int cnt = 1;

        for(cnt = 2 ; cnt <= n ; cnt++){
            string cpy = "";
            

            for(int i = 0 ; i < s.size() ; i++){
                int count = 1;

                while(i + 1 < s.size() && s[i] == s[i + 1]){
                   count++;
                   i++;
                }

                cpy += to_string(count) + s[i];
            }
            s = cpy;
        }
        return s;
    }
};