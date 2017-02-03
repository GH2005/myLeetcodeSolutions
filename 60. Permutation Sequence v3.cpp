class Solution {
public:
    string getPermutation(int n, int k) {
        
        int fact = 1;
        for (int i = 1; i <= n; i++) fact *= i;
        if (k < 1 || fact < k) return "";
        if (fact == 1) return "1";
        
        string res = "123456789";
        res = res.substr(0, n);
        // decide the digits in the permutation one by one
        k--;    // becomes zero-based
        int left = 0;
        for (int divisor = n; divisor >= 2; divisor--) {
            fact /= divisor;
            int q = k / fact;
            k = k % fact;
            int iTarg = left + q;
            swap(res[left], res[iTarg]);
            for (int i = iTarg - 1; i >= left + 1; i--)
                swap(res[i], res[i+1]);
            left++;
        }

        return res;
    }
};
