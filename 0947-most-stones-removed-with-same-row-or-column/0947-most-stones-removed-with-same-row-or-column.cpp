class DisjointSet {
    public:
    vector<int>parent,rank,size;
    public:

    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n + 1);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }
   
   int findUltimateParent(int node){
    if(node == parent[node])
    return node;
    return parent[node] = findUltimateParent(parent[node]);
   }

   void unionByRank(int u,int v){
    int pu = findUltimateParent(u);
    int pv = findUltimateParent(v);

    if(pu == pv)
    return ;
    if(rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else if(rank[pu] < rank[pv]){
        parent[pu] = pv;
    }
    else{
        parent[pv] = pu;
        rank[pu]++;
    }
    return;
   }

   void unionBySize(int u,int v){

    int pu = findUltimateParent(u);
    int pv = findUltimateParent(v);

    if(pu == pv)
    return;
    if(size[pu] > size[pv]){
        parent[pv] = pu;
        size[pu] += size[pv];
    }

   else {
        parent[pu] = pv;
        size[pv] += size[pu];
    }
    
   }
   

};
class Solution {
public:
    int removeStones(vector<vector<int>>& grid) {
        int n = 0;
        int m = 0;

        for(auto it : grid){
            n = max(n,it[0]);
            m = max(m,it[1]);
        }

        DisjointSet ds(n+m+1);
        map<int,int>mp;

        for(auto it : grid){
            int row = it[0];
            int col = it[1] + n + 1;

            ds.unionBySize(row,col);
            mp[row] = 1;
            mp[col] = 1;

        }

        int cnt = 0;

        for(auto it : mp){
            if(it.first == ds.findUltimateParent(it.first))
            cnt++;
        }

      return grid.size() - cnt;

    }
};