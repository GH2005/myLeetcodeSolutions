class Solution {
public:
    string convertToBase7(int num) {
        bool neg = false;
        if (num < 0) neg = true, num = -num;
        string res;
        do {
            res.push_back(num % 7 + '0');
            num /= 7;
        } while (num != 0);
        if (neg) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};
