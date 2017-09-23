class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int ig = 0, is = 0; ig < g.size() && is < s.size(); is++)
        {
            int greed = g[ig], size = s[is];
            if (greed <= size) ig++, res++;
        }
        return res;
    }
};
