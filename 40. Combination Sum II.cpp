class Solution {
    void dp(int start) {// we have got a range [start, this->len)
        int prevCand = -100; // initially it will never be the same as a candidate
        for (int i = start; i < this->len; i++) {// (*this->pCandidates)[i]
            int cand = (*this->pCandidates)[i];
            // cand should not be repetitive
            if (cand == prevCand) continue;
            prevCand = cand;
            currSum += cand;
            this->pSelected->push_back(cand);
            bool needQuit = false;
            if (currSum >= this->tgt) {
                if (currSum == this->tgt) this->pRes->push_back(*this->pSelected);
                needQuit = true;
            }
            else {
                // recursive dp call
                if (i < this->len - 1) this->dp(i + 1);
            }
            currSum -= cand;
            this->pSelected->pop_back();
            if (needQuit) break;
        }
    }
    
    // some variables to be accessed by *this->dp(...)*
    vector<int> *pCandidates;
    int len;
    int tgt;
    int currSum;
    vector<int> *pSelected;
    vector<vector<int>> *pRes;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // preparations and an edge case (if it really is)
        vector<vector<int>> res;
        this->len = candidates.size();
        if (this->len == 0) return res;
        this->pRes = &res;
        vector<int> selected;
        this->pSelected = &selected;
        this->tgt = target;
        this->pCandidates = &candidates;
        this->currSum = 0;
        
        // sort *this->pCandidates
        sort(this->pCandidates->begin(), this->pCandidates->end());
        
        // run *dp(...)* and return the results
        this->dp(0);
        return res;
    }
};
