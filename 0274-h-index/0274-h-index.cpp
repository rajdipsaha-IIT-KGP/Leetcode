class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();

        sort(citations.rbegin(),citations.rend());
        int cnt = 1;
        for(int i = 0 ; i < n ; i++){
          if(citations[i] >= cnt){
            cnt++;
          } else {
            return cnt - 1;
          }
        }
        return cnt - 1;
    }
};