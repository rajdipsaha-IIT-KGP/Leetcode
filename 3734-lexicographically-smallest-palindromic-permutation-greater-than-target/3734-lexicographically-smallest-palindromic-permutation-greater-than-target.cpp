class Solution {
public:
    char mc = '$';
    int half = 0;
    string ans = "";

    bool f(string &curr,string &target,vector<int> &hash,bool greater,int index){
       if(index == half){
         string str = curr;
         string rp = curr;
         if(mc != '$')
         str += mc;
         reverse(rp.begin(),rp.end());
         str += rp;
         if(str > target){
            ans = str;
         return true;
         }
         return false;
       }

       for(int i = 0 ; i < 26 ; i++){
         if(hash[i] == 0)
         continue;

         if(!greater && (i+'a' < target[index]))
         continue;

         bool isGreaterUsed = greater || ((i+'a') > target[index]);
         
         curr.push_back(i+'a');
         hash[i]--;
         if(f(curr,target,hash,isGreaterUsed,index + 1))
         return true;
         curr.pop_back();
         hash[i]++;
       }
       return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        

        vector<int>hash(26,0);
        

        for(int i = 0 ; i < n ; i++){
            hash[s[i] - 'a']++;
        }
        
        int oddCount = 0;

        vector<int>cpy(26,0);

        for(int i = 0 ; i < 26 ; i++){
            cpy[i] = hash[i] / 2;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(hash[i] % 2 != 0){
                oddCount++;
                mc = i+'a';
            }
        }

        if(oddCount > 1)
        return "";
        
        string curr = "";
        half =  n / 2;
        f(curr,target,cpy,false,0);

        return ans;
    }
};