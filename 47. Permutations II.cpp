class Solution {
    // members
    
    int len = 0;
    vector<int> *pNums = nullptr;
    vector<vector<int>> res;
    vector<bool> used;
    vector<int> curr;
    
    void backtracking(int round) {
        
        unordered_map<int, bool> same;
        for (int iNum = 0; iNum < this->len; iNum++) {
            if (used[iNum]) continue;
            int theNum = (*this->pNums)[iNum];
            if (same[theNum]) continue;
            used[iNum] = true;
            curr.push_back(theNum);
            same[theNum] = true;
            if (round == this->len - 2) this->res.push_back(curr);
            else this->backtracking(round + 1);
            used[iNum] = false;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        this->len = nums.size();
        this->pNums = &nums;
        this->res.clear();
        if (this->len == 0) return this->res;
        if (this->len == 1) {
            this->res.push_back(vector<int>{nums[0]});
            return this->res;
        }
        this->used = vector<bool>(this->len, false);
        this->curr.clear();
        this->backtracking(-1);
        return this->res;
    }
};
