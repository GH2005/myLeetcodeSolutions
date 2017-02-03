class Solution {
public:
    string getPermutation(int n, int k) {
        
        int fact = 1;
        for (int i = 1; i <= n; i++) fact *= i;
        if (k < 1 || fact < k) return "";
        if (fact == 1) return "1";
        
        bool used[10] = {};
        string res;
        // decide the digits in the permutation one by one
        k--;    // becomes zero-based
        for (int divisor = n; divisor >= 1; divisor--) {
            fact /= divisor;
            int q = k / fact;
            k = k % fact;
            
            for (int v = 1; v <= 9; v++) {
                if (used[v]) continue;
                if (q == 0) {
                    res += v + '0';
                    used[v] = true;
                    break;
                }
                else q--;
            }
        }

        return res;
    }
};
