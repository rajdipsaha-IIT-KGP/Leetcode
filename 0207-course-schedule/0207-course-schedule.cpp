class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>topoSort;
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);

        for(int i = 0 ; i < prerequisites.size() ; i++){
           indegree[prerequisites[i][0]]++;
           adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int>q;

        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0)
            q.push(i);
        }

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
        if(topoSort.size() == numCourses)
        return true;
        return false;
    }
};