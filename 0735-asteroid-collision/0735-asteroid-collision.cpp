class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>st;
        int n = a.size();
        for(int i = 0 ; i < n ; i++){
            bool flag = true;
            while(!st.empty() && st.back() > 0 && a[i] < 0 && flag){
                if(st.back() == abs(a[i])){
                    flag = false;
                    st.pop_back();
                }
                else if(st.back() < abs(a[i])){
                    st.pop_back();
                }
                else{
                    flag = false;

                }
            }
            if(flag)
            st.push_back(a[i]);
        }
        return st;
    }
};