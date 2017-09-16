class Solution {
public:
    int longestPalindrome(string s) {
        int hashTable['z' + 1 - 'A'] = {};
        for (char ch : s) hashTable[ch - 'A']++;
        bool singleton = false;
        int res = 0;
        for (int c: hashTable)
        {
            if (c % 2 == 1) singleton = true, c--;
            res += c;
        }
        return res + singleton;
    }
};
