class Solution {
public:
   pair<int,int> getCoord(int num,int n){
      int row_top = (num - 1) / n;
      int rb = n - 1 - row_top;
      int col = (num-1)%n;
      if((n%2 == 0 && rb % 2 == 0) || (n%2 != 0 && rb % 2 != 0))
      return {rb,n-1-col};
      return {rb,col};
   }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>>vis(n,vector<int>(n,0));

        vis[n-1][0] = 1;
        queue<int>q;
        q.push(1);
        int steps = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int x = q.front();
                q.pop();
                if(x == n*n)
                return steps;

                for(int k = 1 ; k <= 6 ; k++){
                    if(x+k > n*n)
                    break;
                    pair<int,int>coord = getCoord(x+k,n);
                    int row = coord.first;
                    int col = coord.second;

                    if(vis[row][col])
                    continue;
                    vis[row][col] = 1;

                    if(board[row][col] == -1){
                        q.push(x+k);
                    } else {
                        q.push(board[row][col]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};