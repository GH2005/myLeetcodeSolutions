class Solution {
public:
    int findComplement(int num) {
        int filter = 0x80000000;
        int temp = num << 1;
        while (temp > 0) { filter >>= 1; temp <<= 1; }
        return ~(num | filter);
    }
};
