class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "";
        bool neg = (numerator > 0) ^ (denominator > 0);
        string res;
        if (neg) res += "-";
        unsigned int absNum = llabs(numerator);
        unsigned int absDen = llabs(denominator);
        unsigned int q = absNum / absDen;
        res += to_string(q);
        long long rem = absNum % absDen;
        if (rem == 0) return res;
        res += ".";
        unordered_map<int, int> uomap;
        uomap[rem] = res.size();
        while (rem != 0) {
            rem *= 10;
            res += (rem / absDen) + '0';
            rem %= absDen;
            if (uomap[rem] > 0) {
                res.insert(uomap[rem], "(");
                res += ')';
                return res;
            }
            else uomap[rem] = res.size();
        }
        return res;
    }
};
