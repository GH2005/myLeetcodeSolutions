class Solution {
public:
    bool isValidSerialization(string preorder) {
        // invalid input (if possible)
        int sz = preorder.size();
        if (sz == 0) return false;
        
        // the indicator showing how many pound signs are still needed
        int remaining = 1;
        
        // go over the string
        int pos = 0;
        while (pos < sz) {
            if (preorder[pos] == '#') {
                remaining --;
                pos += 2; 
            }
            else {
                remaining ++;
                while (pos < sz && preorder[pos] != ',') pos ++;
                pos ++;
            }
            if (pos < sz && remaining == 0) return false;
        }
        
        // decide the result by evaluating "remaining"
        if (remaining == 0) return true;
        else return false;
    }
};
