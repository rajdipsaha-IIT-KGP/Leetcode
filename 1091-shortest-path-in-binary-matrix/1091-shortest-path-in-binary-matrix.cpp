class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0 || grid[n - 1][n - 1])
        return -1;
        
        queue<pair<int,pair<int,int>>>q;

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        q.push({1,{0,0}});

        dist[0][0] = 1;

        while(!q.empty()){
           int distance = q.front().first;
           int row = q.front().second.first;
           int col = q.front().second.second;

           if(row == n - 1 && col == n - 1)
           return distance;

           q.pop();

           for(int delrow = -1 ; delrow <= 1 ; delrow++){
            for(int delcol = -1; delcol <= 1 ; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 0 && (distance + 1 < dist[nrow][ncol])){
                    dist[nrow][ncol] = distance + 1;
                    q.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
           }
        }
        return -1;
    }
};