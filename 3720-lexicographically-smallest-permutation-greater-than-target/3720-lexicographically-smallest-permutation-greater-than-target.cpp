class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int>hash(26,0);

        for(int i = 0 ; i < n ; i++){
            hash[s[i] - 'a']++;
        }

        string ans = "";


        for(int i = 0 ; i < n ;i++){
           if(hash[target[i] - 'a'] > 0){
             hash[target[i] - 'a']--;
             string suff = target.substr(i+1);
             string greatest = "";

             for(int j = 25 ; j >= 0 ; j--)
             if(hash[j] > 0){
             greatest.append(hash[j],j+'a');
             }

             if(greatest > suff){
                ans.push_back(target[i]);
                continue;
             } else {
                hash[target[i] - 'a']++;
             }
           }

          bool found = false;

for(int j = target[i] - 'a' + 1; j <= 25; j++){
    if(hash[j] > 0){
        ans.push_back(j + 'a');
        hash[j]--;
        found = true;
        break;
    }
}

if(!found)
    return "";
           for(int j = 0 ; j <= 25 ; j++){
            if(hash[j] > 0)
            ans.append(hash[j],j + 'a');
           }
           return ans; 
        }
        return "";
    }
};