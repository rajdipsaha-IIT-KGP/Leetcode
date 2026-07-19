class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        stack<char>st;
        map<char,vector<int>>mp;

        for(int i = 0 ; i < n ; i ++){
            mp[s[i]].push_back(i);
        }

        string ans = "";
        
       
        vector<int>vis(26,0);

        for(int i = 0 ; i < n ; i++){
            
              if(vis[s[i] - 'a'])
               continue;
               while(!st.empty() && st.top() > s[i]){
                 bool isRepeatingafter = false;
                  vector<int>temp = mp[st.top()];
                  for(int k = 0 ; k < temp.size() ; k++)
                  {
                    if(temp[k] > i){
                        isRepeatingafter = true;
                        break;
                    }
                  }
                  if(!isRepeatingafter)
                  break;
                  else {
                    vis[st.top() - 'a'] = 0;
                    st.pop();
                  }
               }
               
            vis[s[i] - 'a'] = 1;
            st.push(s[i]);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
       return ans;
    }
};