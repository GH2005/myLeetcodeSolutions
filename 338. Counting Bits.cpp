class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(1);
        if (num == 0) return res;
        res.push_back(1);
        if (num == 1) return res;
        int cGroups = log2(num);
        // construct the vector
        for (int i = 0, prevSize = 2; i < cGroups; i++, prevSize <<= 1)
        {
            for (int prevPos = 0; prevPos < prevSize; prevPos++)
                res.push_back(res[prevPos] + 1);
        }
        res.resize(num+1);
        return res;
    }
};
