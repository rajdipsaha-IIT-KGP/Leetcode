class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>adj[n];

        vector<int>indegree(n,0);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;

        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0)
            q.push(i);
        }

      vector<int>topoSort;

      while(!q.empty()){
        int node = q.front();
        q.pop();

        topoSort.push_back(node);
        
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0)
            q.push(it);
        }
      }

      return topoSort.size() == n;
        
    }
};