class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int cnt = 0;

        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

               if(!vis[i][j] && grid[i][j] == '1'){
                vis[i][j] = 1;
                 cnt++;
                 q.push({i,j});

                  while(!q.empty())
                {     int row = q.front().first;
                      int col = q.front().second;
                     q.pop();
                    for(int k = 0 ; k < 4 ; k++){
                    int nrow = delrow[k] + row;
                    int ncol = delcol[k] + col;

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                  }
                 }
               }

            }
        }

        return cnt;


    }
};