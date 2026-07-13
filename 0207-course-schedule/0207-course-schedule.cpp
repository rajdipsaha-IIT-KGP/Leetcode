class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indegree(n,0);

        for(int i = 0 ; i < prerequisites.size() ; i++){
            indegree[prerequisites[i][0]]++;
        }

        vector<int>adj[n];

        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int>q;

        for(int i = 0 ; i < n ; i++){
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