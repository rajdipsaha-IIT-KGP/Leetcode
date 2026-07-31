class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefixMx(n,0);
        vector<int>suffixMx(n,0);

        prefixMx[0] = height[0];
        suffixMx[n - 1] = height[n - 1];

        int cnt = 0;

        for(int i = 1 ; i < n ; i++){
          prefixMx[i] = max(prefixMx[i - 1],height[i]);
          suffixMx[n - i - 1] = max(suffixMx[n - i],height[n - i - 1]);
        }

        for(int i = 0 ; i < n ; i++){
            if(height[i] <= prefixMx[i] && height[i] <= suffixMx[i]){
                cnt += abs(height[i] - min(prefixMx[i],suffixMx[i]));
            }
        }
        return cnt;
    }
};