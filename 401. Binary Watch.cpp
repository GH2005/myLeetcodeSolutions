// nearly copied
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int m = 0; m < 12; m++)
        for (int n = 0; n < 60; n++)
            if (bitset<10>((m << 6) + n).count() == num)
                res.emplace_back(to_string(m) + (n<10 ? ":0" : ":") + to_string(n));
        return res;
    }
};
