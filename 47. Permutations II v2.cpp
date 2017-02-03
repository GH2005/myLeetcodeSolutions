class Solution {
    // members
    
    int len = 0;
    vector<int> *pNums = nullptr;
    vector<vector<int>> res;
    
    void backtracking(int round) {
        int left = round + 1;
        int &rLeft = (*this->pNums)[left];
        unordered_map<int, bool> same;
        for (int iNum = left; iNum < this->len; iNum++) {
            int &theNum = (*this->pNums)[iNum];
            if (same[theNum]) continue;
            same[theNum] = true;
            swap(rLeft, theNum);
            if (round == this->len - 3) this->res.push_back(*pNums);
            else this->backtracking(round + 1);
            swap(rLeft, theNum);
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
        this->backtracking(-1);
        return this->res;
    }
};
