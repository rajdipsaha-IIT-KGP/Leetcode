class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int>vis(n,0);

        vector<int>suspiciousFunctioncalled(n,0);

        for(int i = 0; i < invocations.size() ; i ++){
          adj[invocations[i][0]].push_back(invocations[i][1]);
          
        }

        queue<int>q;
        q.push(k);
        vis[k] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

      vector<int>ans;

       for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (vis[u] == 0 && vis[v] == 1) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
       }

      for(int i = 0 ; i < n ; i++){
        if(vis[i] ==1){
            continue;
        }
        ans.push_back(i);
      }
      return ans;
    }
};