class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
         
         
         int mx = 0;

        for(auto it : st){
          if(st.find(it + 1) == st.end()){
            int cnt = 1;
            int cpy = it - 1;
             while(st.find(cpy) != st.end()){
                cnt++;
                cpy--;
             }
             mx = max(mx,cnt);
          }
        }
        return mx;

    }
};