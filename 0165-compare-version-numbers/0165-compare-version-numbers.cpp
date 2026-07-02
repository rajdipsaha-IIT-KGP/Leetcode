class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n = version1.size();
        int m = version2.size();

        int i = 0 ;
        int j = 0;

        while(i < n || j < m){
            int x = 0;
            int y = 0;

            while(i < n && version1[i] != '.'){
                x = 10 * x + (version1[i] - '0');
                i++;
            }
            while(j < m && version2[j] != '.'){
                y = 10 * y + (version2[j] - '0');
                j++;
            }

            if(x > y)
            return 1;
            if(x < y)
            return -1;
            if(i < n)
            i++;
            if(j < m)
            j++;
        }
        return 0;
    }
};