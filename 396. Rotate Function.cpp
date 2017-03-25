class Solution {
    int exclusiveSum[100000];
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        if (len <= 1) return 0;
        int sum = 0;
        for (int pos = 0; pos < len; pos++) sum += A[pos];
        for (int pos = 0; pos < len; pos++) this->exclusiveSum[pos] = sum - A[pos];
        int maxF = 0;
        for (int pos = 0; pos < len; pos++) maxF += pos * A[pos];
        int prev = maxF;
        int start = 0;
        for (int k = 0; k < len; k++) {
            start = (start + len - 1) % len;
            int currF = prev + this->exclusiveSum[start] - (len-1)*A[start];
            maxF = max(maxF, currF);
            prev = currF;
        }
        return maxF;
    }
};
