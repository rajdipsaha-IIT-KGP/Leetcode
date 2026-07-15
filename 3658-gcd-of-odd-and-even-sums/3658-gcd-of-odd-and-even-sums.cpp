class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;
         
         oddSum = 0;
         evenSum = 0;

         int cnt1 = 1;
         int cnt2 = 2;

        for(int i = 1 ; i <= n ; i++){
           oddSum += cnt1;
           evenSum += cnt2;
           cnt1 += 2;
           cnt2 += 2;
        }

        return gcd(oddSum,evenSum);
    }
};