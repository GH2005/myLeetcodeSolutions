class Solution {
    int len;
    int tgt;
    vector<vector<int>> res;
    vector<int> stk;
    int currSum = 0;
    vector<int> *aCand;
    void bt(int pos)
    {
        if (len <= pos) return;
        // (*aCand)[pos] can be used multiple times
        int value = (*aCand)[pos];
        int count = 0;
        while (this->currSum < this->tgt)
        {
            this->bt(pos+1);
            this->stk.push_back(value);
            this->currSum += value;
            count++;
        }
        if (this->currSum == this->tgt) this->res.push_back(this->stk);
        this->stk.resize(this->stk.size() - count);
        this->currSum -= value * count;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->len = candidates.size();
        this->res.clear();
        this->tgt = target;
        this->aCand = &candidates;
        // sort(candidates.begin(), candidates.end());
        this->bt(0);
        return this->res;
    }
};
