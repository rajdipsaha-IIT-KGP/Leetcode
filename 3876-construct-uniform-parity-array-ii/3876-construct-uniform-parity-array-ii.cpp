class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mnOdd = INT_MAX;

        for (int x : nums) {
            if (x % 2 != 0) {
                mnOdd = min(mnOdd, x);
            }
        }

        
        if (mnOdd == INT_MAX)
            return true;

        bool makeOdd = true;
        bool makeEven = true;

        for (int x : nums) {

           
            if (x % 2 == 0 && x <= mnOdd) {
                makeOdd = false;
            }

            
            if (x % 2 != 0 && x <= mnOdd) {
                makeEven = false;
            }
        }

        return makeOdd || makeEven;
    }
};