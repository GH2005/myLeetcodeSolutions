class Solution {
    int len;
    vector<vector<string>> res;
    string *aStr;
    vector<string> stk;
    void bt(int start)
    {
        if (this->len <= start)
        {
            this->res.push_back(this->stk);
            return;
        }
        for (int pos = start; pos < this->len; pos++)
        {
            // check the state of palindromic
            int left = start, right = pos;
            while (left <= right && (*this->aStr)[left] == (*this->aStr)[right])
                left++, right--;
            // explore farther if palindromic
            if (right < left)
            {
                this->stk.push_back(this->aStr->substr(start, pos+1-start));
                this->bt(pos+1);
                this->stk.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        this->len = s.size();
        this->res.clear();
        if (this->len == 0) return this->res;
        if (this->len == 1)
        {
            this->res.push_back(vector<string>{s});
            return this->res;
        }
        this->aStr = &s;
        this->bt(0);
        return this->res;
    }
};
