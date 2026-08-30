class Solution {
public:
    typedef long long ll;

    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();

        vector<string> ans;

        for(int i = 0; i < n; i++) {
            int cpy = nums[i];

            ll x = 1LL;
            int cnt = 0;

            for(int j = 1; j <= 30; j++) {
                if(x > cpy)
                    break;

                x *= 2LL;
                cnt++;
            }

            if(cnt != 0)
                cnt--;

            string s = "";

            while(cpy > 0) {
    int cnt = 25;

    while((1LL << cnt) > cpy)
        cnt--;

    cpy -= (1LL << cnt);
    s += char('a' + cnt);
}

            ans.push_back(s);
        }

        return ans;
    }
};