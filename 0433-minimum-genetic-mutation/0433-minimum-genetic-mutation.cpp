class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        queue<pair<string,int>>q;

        q.push({startGene,0});
        vector<char>ch = {'A','C','G','T'};

        unordered_set<string>st(bank.begin(),bank.end());

        if(st.find(endGene) == st.end())
        return -1;

        while(!q.empty()){
          string s = q.front().first;
          int steps = q.front().second;

          q.pop();

          if(s == endGene)
          return steps;

          for(int i = 0 ; i < s.length() ; i++){
            string org = s;
            for(int j = 0 ; j < 4 ; j++){
                org[i] = ch[j];
                if(st.find(org) != st.end()){
                    q.push({org,steps+1});
                    st.erase(org);
                }
            }

          }
        }
       return -1;
    }
};