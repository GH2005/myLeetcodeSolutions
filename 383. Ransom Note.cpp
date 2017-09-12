class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int hashTable[26] = {};
        for (char c : magazine) hashTable[c-'a']++;
        for (char c : ransomNote)
            if (--hashTable[c-'a'] < 0) return false;
        return true;
    }
};
