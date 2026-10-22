class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int asc = 0;
        int desc = 0;

        for(int i = 1 ; i < n ; i++){
          if(nums[i] == ((nums[i - 1] + 1) % n)){
            asc++;
          }

          if(nums[i - 1] == ((nums[i] + 1) % n)){
            desc++;
          }
        }

        if(asc == n - 1 && nums[0] == 0){
            return 0;
        }
        if(desc == n - 1 && nums[n - 1] == 0){
            return 1;
        }
        if(asc != n - 1 && desc != n - 1){
            return -1;
        }

        if(desc == n - 1)
        reverse(nums.begin(),nums.end());

        int leftOps = 0;
        int rightOps = 0;


        int idx = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                idx = i;
                break;
            }
        }

        leftOps = idx;

         rightOps = n - (idx % n);
        int Ops = 0;

        if(desc == n - 1){
          Ops = 1 + rightOps;
          return min(Ops,1+leftOps);
        }
        if(asc == n - 1){
          Ops = 2 + rightOps;
          return min(Ops,leftOps);
        }
        return 0;
    }
};