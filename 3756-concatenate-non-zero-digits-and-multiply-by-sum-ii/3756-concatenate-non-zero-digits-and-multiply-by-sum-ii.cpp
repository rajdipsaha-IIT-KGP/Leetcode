class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> nonzeroDigit;

        for (char c : s) {
            if (c != '0')
                nonzeroDigit.push_back(c - '0');
        }

        int m = nonzeroDigit.size();

        vector<ll> nonzeroCount(n + 1, 0);
        vector<ll> numberUpto(m + 1, 0);
        vector<ll> digitSum(m + 1, 0);
        vector<ll> pow10(m + 1, 1);

        for (int i = 0; i < n; i++) {
            nonzeroCount[i + 1] = nonzeroCount[i] + (s[i] != '0');
        }

        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10LL) % MOD;
        }

        for (int i = 0; i < m; i++) {
            digitSum[i + 1] = digitSum[i] + nonzeroDigit[i];
            numberUpto[i + 1] =
                (numberUpto[i] * 10LL + nonzeroDigit[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int left = nonzeroCount[l];
            int right = nonzeroCount[r + 1];

            int k = right - left;

            ll x = (numberUpto[right] -
                    (numberUpto[left] * pow10[k]) % MOD +
                    MOD) % MOD;

            ll sum = digitSum[right] - digitSum[left];

            ans.push_back((int)((x * sum) % MOD));
        }

        return ans;
    }
};