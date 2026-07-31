class Solution {
public:
    int romanToInt(string s) {
        long long cnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(i != s.size() - 1){
                if(s[i] == 'I' && s[i+1] == 'V'){
                    cnt+=4;
                    i++;
                    continue;
                }
                if(s[i] == 'I' && s[i+1] == 'X'){
                    cnt+=9;
                    i++;
                    continue;
                }
                if(s[i] == 'X' && s[i+1] == 'L'){
                    cnt+=40;
                    i++;
                    continue;
                }
                if(s[i] == 'X' && s[i+1] == 'C'){
                    cnt+=90;
                    i++;
                    continue;
                }
                if(s[i] == 'C' && s[i+1] == 'D'){
                    cnt+=400;
                    i++;
                    continue;
                }
                if(s[i] == 'C' && s[i+1] == 'M'){
                    cnt+=900;
                    i++;
                    continue;
                }
            }
          if(s[i] == 'I')
          cnt++;
          else if(s[i] == 'V')
          cnt+=5;
          else if(s[i] == 'X')
          cnt+=10;
          else if(s[i] == 'L')
          cnt+=50;
          else if(s[i] == 'C')
          cnt+=100;
          else if(s[i] == 'D')
          cnt+=500;
          else if(s[i] == 'M')
          cnt += 1000;
        }
        return cnt;
    }
};