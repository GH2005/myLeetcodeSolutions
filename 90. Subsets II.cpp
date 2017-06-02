class Solution {
    vector<int> working;
    int len;
    vector<vector<int>> res;
    vector<int> *aNums;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->len = nums.size();
        this->res.resize(1);
        this->aNums = &nums;
        sort(nums.begin(), nums.end());
        this->bt(0);
        return this->res;
    }
private:
    void bt(int start)
    {
        if (start == this->len) return;
        for (int pos = start; pos < this->len; pos++)
        {
            int value = (*this->aNums)[pos];
            if (start < pos && value == (*this->aNums)[pos-1]) continue;
            this->working.push_back(value);
            this->res.push_back(this->working);
            this->bt(pos+1);
            this->working.pop_back();
        }
    }
};
