class Solution {
public:
    int maxOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int rowOffset,int colOffset){
        int n = img1.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++){
                int di = i + rowOffset;
                int dj = j + colOffset;

                if(di < 0 || di >= n || dj < 0 || dj >= n)
                continue;
                if(img1[i][j] != 1)
                continue;
                if(img1[i][j] == img2[i + rowOffset][j + colOffset])
                cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        for(int rowOffset = -n+1 ; rowOffset < n ; rowOffset++){
            for(int colOffset = -n+1 ; colOffset < n ; colOffset++){
                int cnt = maxOverlaps(img1,img2,rowOffset,colOffset);
                ans = max(ans,cnt);
            }
        }

        return ans;

    }
};