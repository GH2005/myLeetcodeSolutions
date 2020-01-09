class Solution {
public:
    vector<int> dailyTemperatures(vector<int> const & t)
    {
        ptrdiff_t const sz = t.size();
        std::vector<int> ret(sz);
        std::stack<ptrdiff_t> unevaluatedIndices;
        for (ptrdiff_t i = 0; i < sz; ++i)
        {
            while ( !unevaluatedIndices.empty() && t[unevaluatedIndices.top()] < t[i] )
            {
                ret[unevaluatedIndices.top()] = i - unevaluatedIndices.top();
                unevaluatedIndices.pop();
            }
            unevaluatedIndices.push(i);
        }
        return ret;
    }
};
