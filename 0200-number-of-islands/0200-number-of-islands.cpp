class Solution {
public:

    void bfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        queue<pair<int,int>>q;

        q.push({r,c});

        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};

        while(!q.empty()){ 
          int row = q.front().first;
          int col = q.front().second;

          q.pop();

          for(int i = 0 ; i < 4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                q.push({nrow,ncol});
                vis[nrow][ncol] = 1;
            }
          }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
         
        int cnt = 0;

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '0')
                continue;
                if(vis[i][j] == 0){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;

    }
};