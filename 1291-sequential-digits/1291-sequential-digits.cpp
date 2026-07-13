class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        if(high < 12)
        return {};
        string s = "123456789";
        
        vector<int>ans;

        for(int len = 2 ; len <= 9 ; len++){//o(1)
            for(int i = 0 ; i <= 9 - len ; i++){//o(1)
                string str = s.substr(i,len);//o(1)
                int x = stoi(str);
                if(x <= high && x >= low)
                ans.push_back(x);
            }
        }
        return ans;
    }
};