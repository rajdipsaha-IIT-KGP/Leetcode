class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0;
        int n = word.size();
   
        vector<int>a(26,0);
    
        for(int i = 0 ; i < n ; i++){
             a[word[i] - 'a']++;
        }
        sort(a.rbegin(),a.rend());
      for(int i = 0 ; i < 26 ; i++){
         cnt += a[i] * ((i / 8) + 1);
      }
        return cnt;
    }
};