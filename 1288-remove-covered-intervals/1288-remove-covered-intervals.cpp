class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
     int n = intervals.size();
     sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
        return a[0] != b[0] ? a[0] <= b[0] : a[1] >= b[1];
     });
     vector<vector<int>>v;

     for(int i = 0 ; i < n ; i++){
        if(v.empty() || v.back()[0] > intervals[i][0] || v.back()[1] < intervals[i][1]){
            v.push_back(intervals[i]);
        }
        if(v.back()[0] <= intervals[i][0] && v.back()[1] >= intervals[i][1])
        continue;
       
     }   
     return v.size();
    }
};