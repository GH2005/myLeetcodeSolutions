// it's incredibly fast
class Solution {
    int hash(char c)
    {
        return c - 'a';
    }
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if (len == 0) return true;
        if (len == 1) return false;
        int hashTable[26] = {};
        for (char ch : s) hashTable[hash(ch)]++;
        // for (int i = 0; i < 26; i++) printf("%d ", hashTable[i]);
        // try finding a number that divides all hash values
        for (int cSections = 2; cSections <= len; cSections++)
        {
            if (len % cSections != 0) continue;
            bool stage1ok = true;
            for (int i = 0; i < 26; i++)
                if (hashTable[i] % cSections != 0) { stage1ok = false; break;}
            if (!stage1ok) continue;
            int secLen = len / cSections;
            bool stage2ok = true;
            for (int posCh = 0; posCh < secLen; posCh++)
            {
                bool chOK = true;
                for (int sec = 1; sec < cSections; sec++)
                {
                    int actualPos = sec * secLen + posCh;
                    if (s[actualPos - secLen] != s[actualPos]) { chOK = false; break; }
                }
                if (!chOK) { stage2ok = false; break; }
            }
            if (stage2ok) return true;
        }
        return false;
    }
};
