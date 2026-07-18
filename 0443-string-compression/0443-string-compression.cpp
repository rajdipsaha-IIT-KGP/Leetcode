class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int index = 0;
        
        while(i < n){
            char curr = chars[i];
            int cnt = 0;
            while(i < n && (curr == chars[i])){
               i++;
               cnt++;
            }
            chars[index] = curr;
            index++;
            if(cnt > 1){
            string s = to_string(cnt);
            for(auto& it : s)
            {
                chars[index++] = it;
            }
        }   
    }
        return index;
    }
};