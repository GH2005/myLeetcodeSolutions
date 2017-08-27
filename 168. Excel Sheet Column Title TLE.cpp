class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0)
        {
            int pos = 0;
            while (pos < res.size() && res[pos] == 'Z')
                res[pos++] = 'A';
            if (pos == res.size()) res += 'A';
            else res[pos] ++;
            n--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
