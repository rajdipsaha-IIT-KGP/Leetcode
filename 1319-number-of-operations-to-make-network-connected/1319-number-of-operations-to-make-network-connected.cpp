class Solution {

  class DisjointSet{
    public:
    vector<int>rank,parent,size;

    DisjointSet(int n){
       rank.resize(n+1,1);
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
        return ;
        if(size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu] = size[pu] + size[pv];
        } else {
            parent[pu] = pv;
            size[pv] = size[pv] + size[pu];
        }
    }

  };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntex = 0;
         if(connections.size() < n-1)
         return -1;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            int pu = ds.findUltimateParent(u);
            int pv = ds.findUltimateParent(v);

            if(pu != pv){
                ds.unionBySize(u,v);
            } else {
                cntex++;
            }
        }
         int nc = 0;
        for(int i = 0 ; i < n ; i++){
            if(i == ds.parent[i])
             nc++;
        }
        if(nc - 1 <= cntex)
        return nc - 1;
        else return -1;
    }
};