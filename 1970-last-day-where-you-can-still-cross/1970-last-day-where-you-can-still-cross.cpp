class Solution {
public:
    bool isPossible(int n, int m, vector<vector<int>>& cells,int mnDays){
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i = 0 ; i <= mnDays - 1 ; i++){
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j = 0 ; j < m ; j++){
            if(grid[0][j] == 0){
                q.push({0,j});
                vis[0][j] = 1;
            }
        }

        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for(int k = 0;  k < 4 ; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] != 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                } 
            }
        }

        for(int j = 0 ; j < m ; j++){
            if(vis[n-1][j] == 1)
            return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0;
        int high = cells.size();
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(row,col,cells,mid)){
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};