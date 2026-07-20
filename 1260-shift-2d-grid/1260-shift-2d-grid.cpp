class Solution {
public:
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int val = n*m ;
        if(k % val == 0)
        return grid;
        k = k % val;
        auto rev = [&](int i,int j){
            while(i < j){
              swap(grid[i / m][i % m],grid[j / m][j % m]);
              i++;
              j--;
            }
        };

        rev(0,val-1);
        rev(0,k-1);
        rev(k,val-1);

        return grid;
    }
};