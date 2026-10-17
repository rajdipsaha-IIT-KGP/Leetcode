class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n,vector<int>(n,0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1){
                    if(i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    }
                }
            }
        }
     
     vector<int>vis(n,0);

     int cnt = 0;

     queue<int>q;

     for(int i = 0 ; i < n ; i++){
       if(!vis[i]){
         cnt++;
         vis[i] = 1;
        q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
       }
     }
     return cnt;

    }
};