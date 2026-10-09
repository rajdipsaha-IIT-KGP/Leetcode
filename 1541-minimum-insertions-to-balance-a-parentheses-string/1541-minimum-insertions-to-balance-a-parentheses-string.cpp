class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        stack<char>st;

        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
            st.push(s[i]);
            continue;
            }
            if(i == n - 1 && s[i] == ')'){
                if(st.empty()){
                    cnt += 2;
                } else {
                    cnt++;
                    st.pop();
                };
                continue;
            }
          if((i != n - 1) && s[i] == ')' && s[i + 1] == ')'){
              if(st.empty()){
               cnt++;
               i++;
               
              } else {
                st.pop();
                i++;
                
              }
              continue;
          }
          if((i != n - 1) && s[i] == ')' && s[i + 1] != ')'){
              if(st.empty()){
               cnt+=2;
               
              } else {
                st.pop();
                cnt++;
            
              }
              continue;
          }
        }
        if(!st.empty()){
            cnt += 2 * st.size();
        }
        return cnt;
    }
};