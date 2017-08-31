class Solution {
public:
    bool isHappy(int n) {
        bool present[1000] = {};
        stringstream ss;
        ss << n;
        char c;
        while (n != 1)
        {
            n = 0;
            while (ss.get(c)) n += (c-'0') * (c-'0');
            if (present[n]) return false;
            present[n] = true;
            ss.clear();
            ss << n;
        }
        return true;
    }
};
