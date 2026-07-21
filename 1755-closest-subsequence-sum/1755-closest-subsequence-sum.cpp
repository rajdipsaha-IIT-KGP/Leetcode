class Solution {
public:
    using ll = long long;

    int minAbsDifference(vector<int>& nums, int goal) {

        int n = nums.size();
        int n1 = n / 2;
        int n2 = n - n1;

        vector<ll> subset1(1 << n1);
        vector<ll> subset2(1 << n2);

        for (int mask = 0; mask < (1 << n1); mask++) {
            ll sum = 0;
            for (int j = 0; j < n1; j++) {
                if (mask & (1 << j))
                    sum += nums[j];
            }
            subset1[mask] = sum;
        }

        for (int mask = 0; mask < (1 << n2); mask++) {
            ll sum = 0;
            for (int j = 0; j < n2; j++) {
                if (mask & (1 << j))
                    sum += nums[n1 + j];
            }
            subset2[mask] = sum;
        }

        sort(subset2.begin(), subset2.end());

        ll ans = LLONG_MAX;

        for (ll sum1 : subset1) {
            ll need = (ll)goal - sum1;

            auto it = lower_bound(subset2.begin(), subset2.end(), need);

            if (it != subset2.end())
                ans = min(ans, abs((ll)goal - (sum1 + *it)));

            if (it != subset2.begin()) {
                --it;
                ans = min(ans, abs((ll)goal - (sum1 + *it)));
            }
        }

        return (int)ans;
    }
};