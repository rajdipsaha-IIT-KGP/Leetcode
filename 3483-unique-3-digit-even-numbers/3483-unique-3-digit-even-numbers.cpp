class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int>st;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < n ; k++){
                    if(i == j || j == k || k == i)
                    continue;
                    int digit = 1*digits[i] + 10 * digits[j] + 100 * digits[k];
                    if(digit >= 100 && !(digit & 1))
                    st.insert(digit);
                }
            }
        }
        return st.size();
     }
}; 