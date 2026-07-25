class DisjointSet {
 public:
 vector<int>parent,size;
 DisjointSet(int n){
    parent.resize(n+1,0);
    size.resize(n+1,1);

    for(int i = 0 ; i <= n ; i ++)
    parent[i] = i;
 }

 int findUltimateParent(int node){
   if(node == parent[node])
   return node;
   return parent[node] = findUltimateParent(parent[node]);
 }

 void unionBySize(int u,int v){
    int pu = findUltimateParent(u);
    int pv = findUltimateParent(v);

    if(pu == pv){
        return;
    }
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
    int kruskal(vector<vector<int>>& edges,int n){
       int cnt = 0;
       DisjointSet ds(n);

       vector<vector<int>>cpy = edges;
       sort(cpy.begin(),cpy.end(),[](vector<int>&a,vector<int>&b){
        return a[2] < b[2];
       });

       int edgesCnt = 0;
       int cost = 0;

       for(int i = 0 ; i < cpy.size() ; i++){
          int u = cpy[i][0];
          int v = cpy[i][1];

          if(ds.findUltimateParent(u) == ds.findUltimateParent(v))
          continue;

          ds.unionBySize(u,v);
          edgesCnt++;
          cost += cpy[i][2];
       }

       if(edgesCnt != n - 1)
       return 1e9;
       return cost;
    }

    int modifiedKruskal(vector<vector<int>> edges, int n, int skipedge){
    DisjointSet ds(n);
    vector<vector<int>> cpy = edges;

    for(int i = 0; i < edges.size(); i++){
        cpy[i].push_back(i);
    }

    sort(cpy.begin(), cpy.end(), [](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });

    int cnt = 0;
    int edgesCnt = 0;      

    for(int i = 0; i < cpy.size(); i++){
        int u = cpy[i][0];
        int v = cpy[i][1];

        if(skipedge == cpy[i][3])
            continue;

        if(ds.findUltimateParent(u) == ds.findUltimateParent(v))
            continue;

        ds.unionBySize(u,v);

        cnt += cpy[i][2];
        edgesCnt++;        
    }
    if(edgesCnt != n - 1)
        return 1e9;

    return cnt;
}

    int forcedKruskal(vector<vector<int>> edges, int n, int forcededge){
        DisjointSet ds(n);
    vector<vector<int>> cpy = edges;

    for(int i = 0; i < edges.size(); i++){
        cpy[i].push_back(i);
    }

    sort(cpy.begin(), cpy.end(), [](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });

    int cnt = 0;
    int edgesCnt = 0;      

    for(int i = 0 ; i < cpy.size() ; i++){
        if(cpy[i][3] == forcededge)
        {
            cnt += cpy[i][2];
            ds.unionBySize(cpy[i][0],cpy[i][1]);
            edgesCnt++;
            break;
        }
    }

    for(int i = 0; i < cpy.size(); i++){
        int u = cpy[i][0];
        int v = cpy[i][1];

        if(forcededge == cpy[i][3])
            continue;

        if(ds.findUltimateParent(u) == ds.findUltimateParent(v))
            continue;

        ds.unionBySize(u,v);

        cnt += cpy[i][2];
        edgesCnt++;        
    }
    if(edgesCnt != n - 1)
        return 1e9;

    return cnt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int orgCost = kruskal(edges,n);

        vector<int>critical;
        vector<int>pseudocritical;

        for(int i = 0 ; i < edges.size() ; i++){
          int skipCost = modifiedKruskal(edges,n,i);
          if(skipCost > orgCost){
            critical.push_back(i);
            continue;
          } 

          int forcedCost = forcedKruskal(edges,n,i);
          if(forcedCost == orgCost)
          pseudocritical.push_back(i);

        }
        vector<vector<int>>ans;
        ans.push_back(critical);
        ans.push_back(pseudocritical);
        return ans; 
    }
};