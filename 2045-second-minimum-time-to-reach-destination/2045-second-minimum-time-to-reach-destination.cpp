class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n];

        for(int i = 0 ; i < edges.size() ; i++){
           adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
           adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);

        dist1[0] = 0;

        pq.push({0,0});
        
        while(!pq.empty()){
          int node = pq.top().second;
          int timePassed = pq.top().first;

          pq.pop();

          if(node == n - 1 && dist2[node] != INT_MAX)
          return dist2[node];

          int div = timePassed / change;
          if(div % 2 == 1)
          timePassed = (div + 1) * change;

          for(auto it : adj[node]){
            int newTime = timePassed + time;
            if(newTime < dist1[it]){
                dist2[it] = dist1[it];
                dist1[it] = newTime;
                pq.push({newTime,it});
            } else if (newTime < dist2[it] && newTime != dist1[it]){
                dist2[it] = newTime;
                pq.push({newTime,it});
            }
          }
        }
        return -1;
    }
};