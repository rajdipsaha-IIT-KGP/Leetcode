class Solution {
public:
    void solve(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));


        for(int i = 0 ; i < n ; i ++){
            for(int j = 0;  j < m ; j ++){
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 'O'){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
              if(grid[i][j] == 'O' && !vis[i][j])
              grid[i][j] = 'X';
            }
        }
      
      return;

    }
};