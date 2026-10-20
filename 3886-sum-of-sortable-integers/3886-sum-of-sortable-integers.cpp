
class Solution {
public:
    vector<int> buildLPSArray(const vector<int>& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);

        int i = 1, j = 0;

        while (i < n) {
            if (pattern[i] == pattern[j]) {
                lps[i++] = ++j;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                lps[i++] = 0;
            }
        }

        return lps;
    }

    bool KMP(const vector<int>& mainArray,
             int start, int len,
             const vector<int>& pattern,
             const vector<int>& lps) {

        int j = 0;

        // Search the pattern in the doubled block
        for (int i = 0; i < 2 * len - 1; i++) {
            int value = mainArray[start + (i % len)];

            while (j > 0 && value != pattern[j]) {
                j = lps[j - 1];
            }

            if (value == pattern[j]) {
                j++;
            }

            if (j == len) {
                return true;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedArray = nums;
        sort(sortedArray.begin(), sortedArray.end());

        int sum = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool isValid = true;

            for (int st = 0; st < n; st += k) {
                vector<int> pattern(
                    sortedArray.begin() + st,
                    sortedArray.begin() + st + k
                );

                vector<int> lps = buildLPSArray(pattern);

                if (!KMP(nums, st, k, pattern, lps)) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                sum += k;
            }
        }

        return sum;
    }
};
