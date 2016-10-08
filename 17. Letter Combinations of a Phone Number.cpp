class Solution {
private:
    char *digi_charidx[10] = { "@@@@", "@@@@", "abc@", "def@", "ghi@", "jkl@",
                                "mno@", "pqrs", "tuv@", "wxyz" };
    int char_count[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
public:
    vector<string> letterCombinations(string digits) {
        // remove '0's and '1's: O(#digits)
        string digits_trim;
        digits_trim.reserve(digits.size());
        for (int i = 0; i < digits.size(); i++) {
            char c = digits[i];
            assert(c >= '0' && c <= '9');
            if (c > '1') digits_trim += c;
        }
        int ctrimmed = digits_trim.size();
        
        // prepare the responsible container: O(#digits)
        vector<string> res;
        if (digits_trim.size() == 0) return res;
        int maxsz = 1;
        for (int i = 0; i < ctrimmed; i++) { // i --- digit index
            maxsz *= char_count[digits_trim[i] - '0'];
        }
        res.reserve(maxsz);
        //
        // main process
        //
        // pattern
        int *pattern = new int[ctrimmed]();
        // save string
        string tmpstr; tmpstr.reserve(ctrimmed);
        for (int i = 0; i < ctrimmed; i++) {    // i-th digit in the trimmed
            tmpstr += digi_charidx[digits_trim[i]-'0'][pattern[i]];
        }
        res.push_back(tmpstr);
        // calculate fst_nonMax_frmRight
        int fst_nonMax_frmRight = ctrimmed - 1;
        while (fst_nonMax_frmRight >= 0
            && pattern[fst_nonMax_frmRight] >= char_count[digits_trim[fst_nonMax_frmRight] - '0'] - 1)
                fst_nonMax_frmRight--;
        while (fst_nonMax_frmRight >= 0) {
            // update pattern
            for (int i = fst_nonMax_frmRight + 1; i < ctrimmed; i++) pattern[i] = 0;
            if (fst_nonMax_frmRight >= 0) pattern[fst_nonMax_frmRight]++;
            // save string
            string tmpstr; tmpstr.reserve(ctrimmed);
            for (int i = 0; i < ctrimmed; i++) {    // i-th digit in the trimmed
                tmpstr += digi_charidx[digits_trim[i]-'0'][pattern[i]];
            }
            res.push_back(tmpstr);
            // calculate new fst_nonMax_frmRight
            fst_nonMax_frmRight = ctrimmed - 1;
            while (fst_nonMax_frmRight >= 0
                && pattern[fst_nonMax_frmRight] == char_count[digits_trim[fst_nonMax_frmRight] - '0'] - 1)
                fst_nonMax_frmRight--;
        }
        
        // clear and return
        delete[] pattern;
        return res;
    }
};
