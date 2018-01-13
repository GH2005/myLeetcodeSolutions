class Solution {
    vector<int> stk;
    vector<vector<int>> *aRes;
    vector<int> *aNums;
    int len;
    void bt(int pos)
    {
        // without this element
        if (pos == len - 1) aRes->push_back(stk);
        else bt(pos + 1);
        // with this elements
        stk.push_back(aNums->at(pos));
        if (pos == len - 1) aRes->push_back(stk);
        else bt(pos + 1);
        stk.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        len = nums.size();
        if (len == 0) return {{}};
        aNums = &nums;
        vector<vector<int>> res; res.reserve(pow(2, len));
        aRes = &res;
        bt(0);
        return res;
    }
};
