class TreeAncestor {
public:
   int rows,cols;
   vector<vector<int>>ancestorTable;
    TreeAncestor(int n, vector<int>& parent) {
         rows = parent.size();
         cols = log2(n) + 1;
         ancestorTable.resize(rows,vector<int>(cols,-1));

         
            for(int row = 0 ; row < n ; row++){
               ancestorTable[row][0] = parent[row];
            }

            for(int j = 1 ; j < cols ; j++){
                for(int row = 0 ; row < n ;row++){
                    if(ancestorTable[row][j - 1] != -1)
                    ancestorTable[row][j] = ancestorTable[ancestorTable[row][j - 1]][j - 1];
                }
            }
         
    }
    
    int getKthAncestor(int node, int k) {
        
         for(int j = 0 ; j < cols ; j++){
            if(k & (1 << j)){
                
                node = ancestorTable[node][j];
            }
            if(node == -1)
            return -1;
         }
         return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */