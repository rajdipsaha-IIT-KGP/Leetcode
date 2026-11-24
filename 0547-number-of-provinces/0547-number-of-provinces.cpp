class Solution {
public:
    void bfs(int node,vector<int>& vis,vector<vector<int>>& adj){
       vis[node] = 1;
       queue<int>q;
       q.push(node);

       while(!q.empty()){
         int n = q.front();
         q.pop();

         for(auto it : adj[n]){
            if(vis[it] == 0){
                q.push(it);
                vis[it] = 1;
            }
         }
       }
       return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n,vector<int>(n,0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int>vis(n,0);

        for(int i = 0 ; i < n ; i++){
          if(!vis[i]){
            cnt++;
            bfs(i,vis,adj);
          }
        }

         return cnt;
    }
};