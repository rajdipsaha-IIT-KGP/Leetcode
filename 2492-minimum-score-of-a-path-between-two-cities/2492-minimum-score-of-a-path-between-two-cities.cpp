class Solution {
public:
    int minScore(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        
        for(int i = 0 ; i < edges.size() ; i++){
          adj[edges[i][0]-1].push_back({edges[i][1]-1,edges[i][2]});
          adj[edges[i][1]-1].push_back({edges[i][0]-1,edges[i][2]});
        }

        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({INT_MAX,0});
        dist[0] = INT_MAX;

        while(!pq.empty()){
            int currDist = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            
            for(auto it : adj[node]){

                int nnode = it.first;
                int wt = it.second;
                int newwt = min(wt,currDist);

                if(newwt < dist[nnode]){
                   dist[nnode] = newwt;
                   pq.push({dist[nnode],nnode});
                }

            }
        }
        return dist[n-1];
    }
};