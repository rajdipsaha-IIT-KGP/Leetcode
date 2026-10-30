class Solution {
public:
    typedef long long ll;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
       
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }

        vector<vector<ll>>dist(n,vector<ll>(k+1,LLONG_MAX));

                
priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;

         pq.push({0,{0,1}}); // dist,node,state;
         dist[0][1] = 0;
        
        while(!pq.empty()){
            ll d = pq.top().first;
            ll node = pq.top().second.first;
            ll cnt = pq.top().second.second;

            pq.pop();

            if(d != dist[node][cnt])
                continue;

            if(node == n - 1)
                return (int)d;

            for(auto it : adj[node]){
                ll newCnt = 0;
                ll neigh = it.first;
                ll wt = it.second;

                if(labels[node] == labels[neigh])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if(newCnt > k)
                    continue;
                else{
                    if(dist[neigh][newCnt] > wt + d)
                    {
                        dist[neigh][newCnt] = wt + d;
                        pq.push({wt + d,{neigh,newCnt}});
                    }
                }
            }

            
        }
        
        return -1;
            
    }
};