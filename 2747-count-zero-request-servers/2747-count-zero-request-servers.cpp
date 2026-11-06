class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        map<int,int>mp;
        for(int i = 0 ; i < queries.size() ; i++){
            mp[queries[i]] = i;
        }
        sort(queries.begin(),queries.end());
        sort(logs.begin(),logs.end(),[&](vector<int>a,vector<int>b){
          return a[1] < b[1];
        });

        int l = 0;
        int r = 0;

        int m = logs.size();

        vector<int>ans(queries.size(),0);

        unordered_map<int,int>freqMap;

      for(int i = 0 ; i < queries.size() ; i++){
        int start = queries[i] - x;
        int end = queries[i];

        while(r < m && logs[r][1] <= end){
            freqMap[logs[r][0]]++;
            r++;
            
        }

        while(l < m && logs[l][1] < start){
            if(freqMap[logs[l][0]]){
                freqMap[logs[l][0]]--;
                if(freqMap[logs[l][0]] == 0)
                freqMap.erase(logs[l][0]);
            }
            l++;
        } 
        
        ans[mp[queries[i]]] = n - freqMap.size();
      }
      return ans;
    }
};