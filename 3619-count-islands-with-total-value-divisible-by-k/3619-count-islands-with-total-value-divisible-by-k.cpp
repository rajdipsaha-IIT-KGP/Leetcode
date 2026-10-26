class Solution {
public:
   typedef long long ll;
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

       vector<vector<int>>vis(n,vector<int>(m,0));
       queue<pair<int,int>>q;
       
       vector<int>delrow = {-1,0,1,0};
       vector<int>delcol = {0,1,0,-1};

       int cnt = 0;

       for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 0)
            continue;
            if(vis[i][j])
            continue;

            ll sum = 1LL * grid[i][j];

            q.push({i,j});
            vis[i][j] = 1;

            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();
               
                for(int k = 0 ; k < 4 ; k++){
                    int nrow = delrow[k] + row;
                    int ncol = delcol[k] + col;

                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] != 0){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                        sum += 1LL * grid[nrow][ncol];
                    }
                }
            }
            if(sum % k == 0)
            cnt++;
        }
       }

       return cnt;

    }
};