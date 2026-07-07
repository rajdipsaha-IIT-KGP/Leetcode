class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        stack<int>st;

        int cpy = n;
        while(cpy){
            int digit = cpy % 10;
            if(digit != 0){
                st.push(digit);
            }
            cpy /= 10;
        }
       ll x = 0LL;
       ll sum = 0LL;

       while(!st.empty()){
          int d = st.top();
          x = 10 * x + d * 1LL;
          sum += d * 1LL;
          st.pop();
       }

       return sum * x;
    }
};