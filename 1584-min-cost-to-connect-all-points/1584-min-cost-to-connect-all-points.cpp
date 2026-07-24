class DisjointSet{
    public:
    vector<int>parent,size;
  DisjointSet(int n){
    parent.resize(n+1,0);
    size.resize(n+1,1);

    for(int i = 0 ; i <= n ; i++){
        parent[i] = i;
    }
  }

  int findUltimateParent(int node){
      if(node == parent[node])
      return node;
      return parent[node] = findUltimateParent(parent[node]);
  }
  void unionBySize(int u,int v){
    int pu = findUltimateParent(u);
    int pv = findUltimateParent(v);

    if(pu == pv)
    return;

    if(size[pu] >= size[pv]){
        size[pu] += size[pv];
        parent[pv] = pu;
    } else {
        size[pv] += size[pu];
        parent[pu] = pv;
    }
    return;
  }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>adj;

        for(int i = 0 ; i < points.size() ; i++){
            for(int j = i + 1 ; j < points.size() ; j++){
                adj.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),i,j});
            }
        }

        int n = points.size();

        DisjointSet ds(n);

        sort(adj.begin(),adj.end());

        int cnt = 0;

        for(int i = 0 ; i < adj.size() ; i++){
            int u = adj[i][1];
            int v = adj[i][2];

            int pu = ds.findUltimateParent(u);
            int pv = ds.findUltimateParent(v);

            if(pu == pv)
            continue;
            
            cnt += adj[i][0];

            ds.unionBySize(u,v);
        }
        return cnt;

    }
};