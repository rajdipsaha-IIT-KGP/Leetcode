class Solution {
public:
    vector<int>generateRows(int n){
        vector<int>ans;
        long long temp = 1LL;
        ans.push_back(1);
        for(int col = 1 ; col < n ; col++){
           temp *= (n - col) ;
           temp /= col;
           ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1 ; i <= numRows ; i++){
            vector<int>temp = generateRows(i);
             ans.push_back(temp);
        }
        return ans;
    }
};