class Solution {
public:
    
    int rootAns = 0;
    int dfs1(vector<int>adj[],vector<int>& countNodes,int node,int parent,int currDistFromRoot){
        rootAns += currDistFromRoot;
        int totalNode = 1;
        for(auto it : adj[node]){
            if(it == parent)
            continue;
           totalNode += dfs1(adj,countNodes,it,node,currDistFromRoot + 1);
        }
        countNodes[node] = totalNode;
        return totalNode;
    }

    void dfs(vector<int>& result,vector<int> adj[] , vector<int>& countNodes,int node,int parent,int n){
       for(auto it : adj[node]){
        if(it == parent)
        continue;
        result[it] = result[node] - countNodes[it] + (n - countNodes[it]);
        dfs(result,adj,countNodes,it,node,n);
       }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>countNodes(n,0);
        vector<int>result(n,0);

        dfs1(adj,countNodes,0,-1,0);
        result[0] = rootAns;

        dfs(result,adj,countNodes,0,-1,n);
        return result;
    }
};