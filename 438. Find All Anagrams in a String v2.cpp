class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenP = p.size();
        vector<int> res;
        if (s.size() < lenP) return res;
        array<int, 26> hashTable{}, controlGroup{};
        auto hash = [](char c)->int{ return c - 'a'; };
        for (char c : p) hashTable[hash(c)]++;
        int pos = 0;
        while (pos < lenP)
        {
            hashTable[hash(s[pos])]--;
            pos++;
        }
        if (hashTable == controlGroup) res.push_back(0);
        while (pos < s.size())
        {
            hashTable[hash(s[pos])]--;
            hashTable[hash(s[pos - lenP])]++;
            pos++;
            if (hashTable == controlGroup) res.push_back(pos - lenP);
        }
        return res;
    }
};
