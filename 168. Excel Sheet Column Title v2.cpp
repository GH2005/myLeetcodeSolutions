// idea from someone else
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        do {
            n--;
            res += n % 26 + 'A';
            n /= 26;
        } while (n > 0);
        reverse(res.begin(), res.end());
        return res;
    }
};
