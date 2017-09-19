class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int len1 = num1.size(), len2 = num2.size();
        bool carry = 0;
        for (int pos1 = len1 - 1, pos2 = len2 - 1;
        0 <= pos1 || 0 <= pos2; pos1--, pos2--)
        {
            int digit = carry;
            if (0 <= pos1) digit += num1[pos1] - '0';
            if (0 <= pos2) digit += num2[pos2] - '0';
            carry = digit / 10;
            res.push_back(digit % 10 + '0');
        }
        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
