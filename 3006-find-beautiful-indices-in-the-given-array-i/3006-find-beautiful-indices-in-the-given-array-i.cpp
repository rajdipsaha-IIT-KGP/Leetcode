class Solution {
public:
    

    vector<int>buildLPSArray(string s){
        int n = s.size();
        int j = 0;
        int i = 1;

        vector<int>lps(n,0);

       while(i < n){
         if(s[i] == s[j]){
            lps[i] = j + 1;
            i++;
            j++;
         } else {
            while(j > 0 && s[i] != s[j])
            j = lps[j - 1];

            if(s[i] == s[j]){
                lps[i] = j + 1;
                j++;
            }
            i++;
         }

       }
       return lps;

    }

    void KMP(string text,string pattern,vector<int>& nums){

        string s = pattern + '$' + text;
        vector<int>lps = buildLPSArray(s);

        int m = pattern.size();
        int n = text.size();

        for(int i = m + 1; i <= m + n ; i++){
            if(lps[i] == m)
          nums.push_back(i - 2*m);
        }
        return;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        vector<int>nums1;
        KMP(s,a,nums1);
        vector<int>nums2;
        KMP(s,b,nums2);

        vector<int>ans;

        for(int i = 0; i < nums1.size(); i++){
            int goal = nums1[i] - k;
          auto it = lower_bound(nums2.begin(),nums2.end(),goal);
          if(it == nums2.end())
          continue;
          if(*it > nums1[i] + k)
          continue;
          ans.push_back(nums1[i]);
        }
        return ans;
    }
};