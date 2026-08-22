class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int cpy = n;
        int prd = 1;

        while(cpy){
          int d = cpy % 10;
          sum += d;
          prd *= d;
          cpy /= 10;
        }
        if((n % (sum+prd) == 0))
        return 1;
        return 0;
    }
};