class Solution {
public:
    string toHex(int numo) {
        if (numo == 0) return "0";
        unsigned num = numo;
        string res;
        while (num != 0)
        {
            int fourBits = num & 15;
            res += fourBits < 10 ? fourBits + '0' : fourBits - 10 + 'a';
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
