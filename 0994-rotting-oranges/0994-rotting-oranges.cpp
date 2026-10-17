class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,pair<int,int>>>q;

        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                q.push({0,{i,j}});
                vis[i][j] = 1;}
            }
        }

        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        int mn = 0;

        while(!q.empty()){
            int t = q.front().first;
            mn = max(t,mn);
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    int newTime = t + 1;
                    q.push({newTime,{nrow,ncol}});
                }
            }
        }

        for(int i = 0 ; i < n ; i ++){
            for(int j =0 ; j < m ;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0)
                return -1;
            }
        }
        return mn;

    }
};