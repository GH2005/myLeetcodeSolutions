class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        
        // change '9's at the last to '0's
        int pos = sz - 1;
        while(pos >= 0 && digits[pos] == 9) {
            digits[pos] = 0;
            pos --;
        }
        
        // add 1 to the first non-nine digit from the last
        if (pos >= 0) {
            digits[pos] ++;
        }
        else {// 999...9 to 1000...0
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
