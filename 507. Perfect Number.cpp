class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        int last = sqrt(num);
        for (int factor = 2; factor <= last; factor++)
        {
            if (num % factor == 0)
                sum += factor + num / factor;
        }
        if (last * last == num) sum -= last;
        return sum == num;
    }
};
