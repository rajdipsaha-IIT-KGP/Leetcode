class Solution {
public:
    bool sumGame(string s) {
        int n = s.size();
        int lq = 0;
        int rq = 0;

        int ls = 0;
        int rs = 0;


        for(int i = 0 ; i < n ; i++){
            if(s[i] == '?'){
              if(i < n / 2){
               lq++;
              } else {
                  rq++;
              }
            } else {
             if(i < n / 2){
                ls += s[i] - '0';
             } else {
                rs += s[i] - '0';
             }
            }
        }

        if((rq+lq)&1)
        return true;

        if((2 * ls + 9 * lq) == (2 * rs + 9 * rq))
        return false;
        return true;
    }
};