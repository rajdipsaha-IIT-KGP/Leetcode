class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        if(n == 1)
        return {0};
        vector<int>indegree(n,0);
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

        queue<int>q;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 1)
            q.push(i);
        }

        while(n > 2){
            int sz = q.size();
            n -= sz;
            while(sz--){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    indegree[it]--;
                    if(indegree[it] == 1)
                    q.push(it);
                }
            }
        }

       vector<int>result;
       while(!q.empty()){
         result.push_back(q.front());
         q.pop();
       }
       return result;
        
    }
};