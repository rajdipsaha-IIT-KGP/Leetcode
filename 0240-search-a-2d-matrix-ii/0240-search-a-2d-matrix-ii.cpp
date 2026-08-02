class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        int n = grid.size();
        int m = grid[0].size();

        int i = 0;
        int j = m - 1;

        while(i < n && j >= 0){
            if(grid[i][j] == target)
            return true;
            else if(grid[i][j] < target){
               i++;
            } else{
              j--;
            }
        }
        return false;
    } 
};