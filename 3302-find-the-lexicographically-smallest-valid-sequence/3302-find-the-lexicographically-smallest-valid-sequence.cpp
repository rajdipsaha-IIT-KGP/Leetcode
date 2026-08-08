class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();


        vector<int>suffixMatching(n,0);

        int p1 = n - 1;
        int p2 = m - 1;

        int cnt = 0;

        while(p1 >= 0){
          if(p2 >= 0 && word1[p1] == word2[p2]){
            p2--;
            cnt++;
          }
         suffixMatching[p1] = cnt;
         p1--;
        }

        vector<int>ans;
        int j = 0;
        int canApplyOperation = true;


        for(int i = 0 ; i < n ; i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
              
              j++;
              if(j == m)
              break;
            } else if((i != n - 1) &&  canApplyOperation && (suffixMatching[i + 1] >= (m - j - 1))){
              canApplyOperation = false;
              ans.push_back(i);
              j++;
            
            }
        }

        if(j == m){
            return ans;
        }
        return vector<int>();
    }
};