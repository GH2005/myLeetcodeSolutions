class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> nextGreaters;
        for (int v : findNums) nextGreaters[v] = -1;
        stack<int> stk;
        for (int v : nums)
        {
            while (!stk.empty() && stk.top() < v)
                nextGreaters[stk.top()] = v, stk.pop();
            if (nextGreaters.find(v) != nextGreaters.end()) stk.push(v);
        }
        vector<int> res;
        for(int v : findNums) res.push_back(nextGreaters[v]);
        return res;
    }
};
