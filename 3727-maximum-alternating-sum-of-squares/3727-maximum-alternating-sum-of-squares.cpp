class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        long long n = a.size();

        
        vector<long long> A(n);
        for (int i = 0; i < n; i++) {
            A[i] = llabs((long long)a[i]);
        }

        sort(A.begin(), A.end());

        vector<long long> b(n);
        long long cnt = n - 1;

        for (long long i = 0; i < n; i += 2) {
            b[i] = A[cnt--];
        }
        for (long long i = 1; i < n; i += 2) {
            b[i] = A[cnt--];
        }

        long long score = 0;

        for (long long i = 0; i < n; i += 2) score += b[i] * b[i];
        for (long long i = 1; i < n; i += 2) score -= b[i] * b[i];

        return score;
    }
};
