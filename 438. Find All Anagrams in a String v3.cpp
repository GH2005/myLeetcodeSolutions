class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenP = p.size();
        vector<int> res;
        if (s.size() < lenP) return res;
        array<int, 26> hashTable{};
        auto hash = [](char c)->int{ return c - 'a'; };
        for (char c : p) hashTable[hash(c)]++;
        int pos = 0;
        while (pos < lenP)
        {
            hashTable[hash(s[pos])]--;
            pos++;
        }
        int validCount = 26;
        for (int i = 0; i < 26; i++)
            if (hashTable[i] != 0) validCount--;
        if (validCount == 26) res.push_back(0);
        while (pos < s.size())
        {
            int &tableItem1 = hashTable[hash(s[pos-lenP])];
            int &tableItem2 = hashTable[hash(s[pos])];
            tableItem1++;
            if (tableItem1 == 1) validCount--;
            else if (tableItem1 == 0) validCount++;
            tableItem2--;
            if (tableItem2 == -1) validCount--;
            else if (tableItem2 == 0) validCount++;
            pos++;
            if (validCount == 26) res.push_back(pos - lenP);
        }
        return res;
    }
};
