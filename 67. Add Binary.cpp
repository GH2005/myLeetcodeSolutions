class Solution {
public:
    string addBinary(string a, string b) {
        int remLenA = a.size(), remLenB = b.size();
        if (remLenA == 0) return b;
        if (remLenB == 0) return a;
        string res(max(remLenA, remLenB) + 1, '0');
        int pos = res.size() - 1;
        int carry = 0;
        auto toChar = [](int digit)->char{ return digit + '0'; };
        auto toInt = [](char ch)->int{ return ch - '0'; };
        while (0 < pos)
        {
            int digit1 = remLenA > 0 && a[--remLenA] == '1' ? 1 : 0;
            int digit2 = remLenB > 0 && b[--remLenB] == '1' ? 1 : 0;
            digit1 ^= carry;
            if (digit1 == 1) carry = 0;
            digit1 ^= digit2;
            if (digit1 == 0 && digit2 == 1) carry = 1;
            res[pos--] = toChar(digit1);
        }
        if (carry == 1) { res[0] = '1'; return res; }
        else return res.substr(1, res.size() - 1);
    }
};
