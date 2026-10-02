class Solution {
public:
   vector<string>ans;
   void f(int n,string &s,int balance,int bracketUsed){
     if(bracketUsed == 2*n){
        if(balance == 0)
        ans.push_back(s);
        return ;
     }
     s.push_back('(');
     f(n,s,balance+1,bracketUsed+1);
     s.pop_back();
     if(balance > 0){
     s.push_back(')');
     f(n,s,balance-1,bracketUsed+1);
     s.pop_back();
     }
   }
    vector<string> generateParenthesis(int n) {
        string s = "";
        f(n,s,0,0);
        return ans;
    }
};