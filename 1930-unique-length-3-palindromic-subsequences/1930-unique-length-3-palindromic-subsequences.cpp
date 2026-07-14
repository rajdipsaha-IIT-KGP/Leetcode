class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
         vector<pair<int,int>>precomputeIndex(26,{-1,-1});

         for(int i = 0 ; i < n ; i++){
            if(precomputeIndex[s[i] - 'a'].first == -1){
                precomputeIndex[s[i] - 'a'].first = i;
            }
            precomputeIndex[s[i] - 'a'].second = i;
         }

         int cnt = 0;

         for(int i = 0 ; i < 26 ; i++){
            if(precomputeIndex[i].first == -1)
            continue;
            set<int>st;

            for(int j = precomputeIndex[i].first + 1 ; j < precomputeIndex[i].second ; j++){
              st.insert(s[j] - 'a');
            }
            cnt += st.size();
         }
         return cnt;
    }
};