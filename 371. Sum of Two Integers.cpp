class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        for (int mask = 1, carry = 0; mask != 0; mask <<= 1)
        {
            int maskedA = a & mask;
            int maskedB = b & mask;
            int theBit = maskedA ^ carry;
            if ((maskedA & carry) != 0) carry = mask << 1;
            else carry = 0;
            if ((theBit & maskedB) != 0) carry = mask << 1;
            theBit ^= maskedB;
            res |= theBit;
        }
        return res;
    }
};
