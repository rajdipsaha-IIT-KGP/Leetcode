class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>> pq;

        vector<vector<int>>healtCounter(n,vector<int>(m,-1));

        if(grid[0][0] == 0){
            pq.push({health,{0,0}});
            healtCounter[0][0] = health;
        } else {
            pq.push({health - 1,{0,0}});
            healtCounter[0][0] = health - 1;
        }
       
       vector<int>delrow = {-1,0,1,0};
       vector<int>delcol = {0,1,0,-1};

        while(!pq.empty()){

            int currHealth = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            if(row == n - 1 && col == m - 1)
            {
                return currHealth >= 1;
            }

             for(int i = 0 ; i < 4; i++){
               int nrow = row + delrow[i];
               int ncol = col + delcol[i];

               if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                  int newHealth = grid[nrow][ncol] == 0 ? currHealth : currHealth - 1;
                  if(newHealth > 0 && newHealth > healtCounter[nrow][ncol]){
                      healtCounter[nrow][ncol] = newHealth;
                      pq.push({newHealth,{nrow,ncol}});
                  }
               }
             }

        }

        return false;
        
    }
};