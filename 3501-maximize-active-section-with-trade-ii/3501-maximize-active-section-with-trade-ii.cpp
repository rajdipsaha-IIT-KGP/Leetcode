class Solution {
public:

   int RMIQ(vector<int>& segmentTree,int low,int high,int l,int r,int index){
    if(r < low || l > high)
    return -1e9;
    if(l >= low && r <= high)
    return segmentTree[index];

    int mid = l + (r - l) / 2;
    return max(RMIQ(segmentTree,low,high,l,mid,2*index+1),RMIQ(segmentTree,low,high,mid+1,r,2*index+2));
   }
   void buildSegmentTree(vector<int>& nums,vector<int>& segmentTree,int l,int r,int index){
     if(l == r){
     segmentTree[index] = nums[l];
     return;
     }

     int mid = l + (r - l) / 2;

     buildSegmentTree(nums,segmentTree,l,mid,2*index + 1);
     buildSegmentTree(nums,segmentTree,mid + 1,r,2*index + 2);
     
     segmentTree[index] = max(segmentTree[2 * index + 1],segmentTree[2 * index + 2]);
   }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int>start;
        vector<int>end;
        vector<int>blockSize;
        vector<int>ans;
        int i = 0;

        while(i < n){
          if(s[i] == '0'){
            int st = i;
            while(i < n && s[i] == '0')
            i++;
            start.push_back(st);
            end.push_back(i -  1);
          } else {
            i++;
          }
        }

        int m = start.size();

        for(int i = 0 ; i < m ; i++){
            blockSize.push_back(end[i] - start[i] + 1);
        }

         int activeCnt = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1')
            activeCnt++;
        }

        if(blockSize.empty()){
        return vector<int>(queries.size(), activeCnt);
      }

        if(blockSize.size() < 2){
            int x = n - blockSize[0];
            vector<int>temp(queries.size(),x);
            return temp;
        }

        vector<int>pairSum(m - 1,0);
        for(int i = 0 ; i < pairSum.size() ; i++){
            pairSum[i] = blockSize[i] + blockSize[i + 1];
        }

       
   
        vector<int>segmentTree(4*(m - 1),0);
        buildSegmentTree(pairSum,segmentTree,0,m - 2,0);

        for(int i = 0 ; i < queries.size() ; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            auto low = lower_bound(end.begin(),end.end(),l) - end.begin();
            auto high = upper_bound(start.begin(),start.end(),r) - start.begin() - 1;

            int maxPairsum = 0;

            if(low < high){
                int firstLen = end[low] - max(l,start[low]) + 1;
                int lastLen = min(r,end[high]) - start[high] + 1;

                if(high - low == 1){
                    maxPairsum = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + blockSize[low + 1];
                    int pair2 = lastLen + blockSize[high - 1];
                    int pair = RMIQ(segmentTree,low + 1,high - 2,0,m-2,0);
                    
                     maxPairsum = max({pair,pair1,pair2});

                }

            }
            ans.push_back(maxPairsum + activeCnt);
        }
     return ans;
    }
};