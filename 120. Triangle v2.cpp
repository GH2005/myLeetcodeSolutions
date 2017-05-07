class Solution {
    struct StackItem {
        int level;
        int pos;
        int state;  // state 0: read this->lastSums and then visit the lower right neighbor
                    // state 1: read the return value and generate new return value
        int sum;
        StackItem(int lvl, int po, int su) : level(lvl), pos(po), sum(su), state(0) {}
    };
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        if (height == 0) return 0;
        if (height == 1) return triangle[0][0];
        vector<int> lastSums(height, 0);
        stack<Solution::StackItem> stk;
        for (int level = 0; level < height; level++) stk.emplace(level, 0, triangle[level][0]);
        int retValue = 0;
        while (!stk.empty()) {
            Solution::StackItem &item = stk.top();
            if (item.level == height - 1) {
                retValue = item.sum;
                lastSums[item.level] = item.sum;
                stk.pop();
            }
            else {
                if (item.state == 0) {
                    item.sum += lastSums[item.level+1];
                    item.state = 1;
                    stk.emplace(item.level+1, item.pos+1, triangle[item.level+1][item.pos+1]);
                }
                else {
                    retValue = min(item.sum, retValue + triangle[item.level][item.pos]);
                    lastSums[item.level] = retValue;
                    stk.pop();
                }
            }
        }
        return retValue;
    }
};
