class Solution {
public:
  typedef long long ll;
    vector<int>prevSmallerElement(vector<int>& heights){
       int n = heights.size();
       vector<int>ans(n,0);

       stack<int>st;

       for(int i = 0 ; i < n ; i++){
          while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
          }
         ans[i] = st.empty() ? -1 : st.top();
         st.push(i);
       }
       return ans;
    }
    vector<int>nextSmallerElement(vector<int>& heights){
       int n = heights.size();
       vector<int>ans(n,0);

       stack<int>st;

       for(int i = n - 1 ; i >= 0 ; i--){
          while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
          }
         ans[i] = st.empty() ? n : st.top();
         st.push(i);
       }
       return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>pse = prevSmallerElement(heights);
        vector<int>nse = nextSmallerElement(heights);
       
        ll cnt = 0LL; 
        ll mx = 0LL;

        for(int i = 0 ; i < n ; i++){
          mx = max(mx,1LL*heights[i] * (nse[i] - pse[i] - 1));
        }
   return (int)mx;
    }
};