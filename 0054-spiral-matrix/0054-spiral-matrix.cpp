class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        int left = 0;
        int top = 0;
        int right = m - 1;
        int bottom = n - 1;
        vector<int>a;

        while(top <= bottom && left <= right){
            for(int i = left ; i <= right ; i++){
              a.push_back(grid[top][i]);
            }
            top++;
            for(int i = top ; i <= bottom ; i++){
                a.push_back(grid[i][right]);
            }
            right--;
            if(top <= bottom){
                for(int i = right ; i >= left ; i--){
                    a.push_back(grid[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom ; i >= top ; i--){
                    a.push_back(grid[i][left]);
                }
                left++;
            }

        }
        return a;
    }
};