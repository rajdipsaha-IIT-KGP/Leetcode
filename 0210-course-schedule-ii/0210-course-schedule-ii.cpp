class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        vector<int>ind(n,0);
        for(int i = 0 ; i < n ; i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }
        for(int i = 0; i < n; i++){
    if(ind[i] == 0){
        q.push(i);
    }
}
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                ind[it]--;
                if(ind[it] == 0)
                q.push(it);
            }
        }
        if(ans.size() != n) return {};
        return ans;
    }
};