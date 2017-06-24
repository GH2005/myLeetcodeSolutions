class Solution {
    inline int hash(char ch) { return ch - 'a'; };
public:
    char findTheDifference(string s, string t) {
        if (s.empty()) return t[0];
        int hashTable[26] = {};
        // 0 -- not existing; 1 -- existing; 2 -- existing and visited
        for (char ch : s) hashTable[hash(ch)]++;
        for (char ch : t)
        {
            int &value = hashTable[hash(ch)];
            if (value == 0) return ch;
            else value--;
        }
    }
};
