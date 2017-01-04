class Solution {
private:
    string shared;
    int cRemainingLefts;
    int cAvailableRights;
    vector<string>* pRes;
    void dp() {
        // the base case
        if (this->cRemainingLefts == 0) {
            // complete the string and add it to *res*
            string temp = this->shared;
            for (int i = 0; i < this->cAvailableRights; i++) temp += ')';
            this->pRes->push_back(temp);
            return;
        }
        
        // recursive calls
        this->shared += '(';
        this->cRemainingLefts --;
        this->cAvailableRights ++;
        dp();
        this->shared.pop_back();
        this->cRemainingLefts ++;
        this->cAvailableRights --;
        
        if (cAvailableRights > 0) {
            this->shared += ')';
            this->cAvailableRights --;
            dp();
            this->shared.pop_back();
            this->cAvailableRights ++;
        }
        
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        // preparation
        vector<string> res;
        this->pRes = &res;
        this->shared.clear();
        this->shared.reserve(2*n);
        this->cRemainingLefts = n;
        this->cAvailableRights = 0;
        
        // when n == 0 or 1
        if (n == 0) return res;
        if (n == 1) {
            res.push_back(string("()"));
            return res;
        }
        
        // recursive calls
        dp();
        
        // after recursive calls, *res* is ready to be returned
        return res;
    }
};
