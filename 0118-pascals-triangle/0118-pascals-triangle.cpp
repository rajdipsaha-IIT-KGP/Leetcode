class Solution {
public:
    vector<int>generateRows(int row){
        vector<int>ans;
        ans.push_back(1);
        
        int cnt = 1;
        for(int i = 1 ; i < row ; i++){
          cnt *= (row - i);
          cnt /= i;
          ans.push_back(cnt);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>>ans;

        for(int i = 1 ; i <= n ; i++){
            vector<int>temp = generateRows(i);
            ans.push_back(temp);
        }
        return ans;
    }
};