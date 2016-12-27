class Solution {
public:
    int addDigits(int num) {
        // the only edge case
        if (num == 0) return 0;
        
        // O(1) solution based on the property found
        int r = num % 9;
        if (r == 0) return 9;
        else return r;
    }
};
