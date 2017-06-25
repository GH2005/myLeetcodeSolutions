class Solution {
    inline char to_hex(int num)
    {
        return num < 10 ? num + '0' : num - 10 + 'a';
    }
public:
    string toHex(int num) {
        if (num == 0) return "0";
        int diff = num < 0 ? num - INT_MIN : num;
        string diffStr;
        while (diff > 0)
        {
            diffStr += this->to_hex(diff % 16);
            diff /= 16;
        }
        reverse(diffStr.begin(), diffStr.end());
        if (num > 0) return diffStr;
        string negRes = "80000000";
        int diffPos = diffStr.size() - 1;
        for (int resPos = 7; 0 <= diffPos && 1 <= resPos; diffPos--, resPos--)
            negRes[resPos] = diffStr[diffPos];
        if (diffPos == 0) negRes[0] = this->to_hex(8 + diffStr[0] - '0');
        return negRes;
    }
};
