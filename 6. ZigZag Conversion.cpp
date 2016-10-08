class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1) {
            return s;
        }
        
        string* rows = new string[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i].reserve(100);
        }
        
        for(int i = 0; i < s.length(); i++) {
            // mod half*2
            int half = numRows - 1;
            int r1 = i % (half*2);
            if (r1 < half) rows[r1] += s[i];
            else rows[half*2 - r1] += s[i];
        }
        
        string res;
        for (int i = 0; i < numRows; i++) {
            res += rows[i];
        }
        
        delete[] rows;
        return res;
    }
};
