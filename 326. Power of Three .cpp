// with reference to the editorial solution
class Solution {
public:
    bool isPowerOfThree(int n) {
        double intPart = 0;
        return n > 0 && modf(log(n) / log(3) + 0.0000000001, &intPart) < 0.0000000002;
    }
};
