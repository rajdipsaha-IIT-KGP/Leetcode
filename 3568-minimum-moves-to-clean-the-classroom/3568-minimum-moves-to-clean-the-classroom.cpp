class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        vector<vector<int>>litter(n,vector<int>(m,0));
        int cnt = 0;

        int sr = 0;
        int sc = 0;


        for(int i = 0 ; i < n ; i++){
            string s = classroom[i];
            for(int j = 0 ; j < m ; j++){
                if(s[j] == 'S'){
                 sr = i;
                 sc = j;
                } else if(s[j] == 'L'){
                    litter[i][j] = cnt;
                    cnt++;
                }
            }
        }

        vector<vector<vector<vector<int>>>>vis(n,vector<vector<vector<int>>>(m,vector<vector<int>>(energy+1,vector<int>(1<<cnt,0))));


        queue<array<int,5>>q;
        q.push({sr,sc,energy,0,0});

        vis[sr][sc][energy][0] = 1;

        int totalLitter = (1 << cnt) - 1;

        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [row,col,e,litterCollection,moves] = q.front();  
                q.pop();  
                if(litterCollection == totalLitter)
                return moves;
                if(e == 0)
                continue;
                for(int i = 0 ; i < 4 ; i++){
                    int nrow = delrow[i] + row;
                    int ncol = delcol[i] + col;

                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && classroom[nrow][ncol] != 'X'){
                        int ne;
                        int newMove;
                        int newLitterCollection = litterCollection;
                        if(classroom[nrow][ncol] == '.'){
                             ne = e - 1;
                             newMove = moves+1;
                             newLitterCollection = litterCollection;
                        } else if(classroom[nrow][ncol] == 'R'){
                            ne = energy;
                            newMove = moves + 1;
                            newLitterCollection = litterCollection;
                        } else if(classroom[nrow][ncol] == 'L'){
                            ne = e - 1;
                            newMove = moves + 1;
                            int pos = litter[nrow][ncol];
                            newLitterCollection |= (1 << pos);
                        } else {
                            ne = e - 1;
                            newMove = moves + 1;
                        }

                        if(!vis[nrow][ncol][ne][newLitterCollection]){
                        q.push({nrow,ncol,ne,newLitterCollection,newMove});
                        vis[nrow][ncol][ne][newLitterCollection] = 1;
                        }
                    
                    }
                }
            }
        }
        return -1;
    }
};