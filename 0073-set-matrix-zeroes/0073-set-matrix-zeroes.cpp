class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>row(n,0);
        vector<int>col(m,0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
               if(grid[i][j] == 0)
               {
                  row[i] = 1;
                  col[j] = 1;
               }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(col[j] == 1 || row[i] == 1){
                    grid[i][j] = 0;
                }
            }
        }

        return;
    }
};