class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenP = p.size();
        vector<int> res;
        if (s.size() < lenP) return res;
        array<int, 26> hashTable1{}, hashTable2{};
        auto hash = [](char c)->int{ return c - 'a'; };
        for (char c : p) hashTable1[hash(c)]++;
        for (int start = 0; start <= s.size() - lenP; start++)
        {
            hashTable2 = hashTable1;
            for (int pos = start; pos < start + lenP; pos++)
                if (--hashTable2[hash(s[pos])] < 0) goto postAddition;
            res.push_back(start);
            postAddition:;
        }
        return res;
    }
};
