class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        if (len <= 1) return 0;
        int sum = 0;
        int maxF = 0;
        for (int pos = 0; pos < len; pos++) { sum += A[pos]; maxF += pos * A[pos]; }
        int currF = maxF;
        for (int k = len - 1; 0 < k; --k) {
            currF = currF + sum - len * A[k];
            maxF = max(maxF, currF);
        }
        return maxF;
    }
};
