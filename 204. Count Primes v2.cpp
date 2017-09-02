class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> isComp(n);
        for (int i = 4; i < n; i += 2) isComp[i] = true;
        isComp[1] = true;
        isComp[0] = true;
        int bound = sqrt(n);
        for (int i = 3; i <= bound; i += 2)
        {
            if (isComp[i]) continue;
            for (int j = i;;j += 2)
            {
                int product = i * j;
                if (product >= n) break;
                isComp[product] = true;
            }
        }
        
        int res = n;
        for (int num = 0; num < n; num++)
            if (isComp[num]) res--;
        return res;
    }
};
