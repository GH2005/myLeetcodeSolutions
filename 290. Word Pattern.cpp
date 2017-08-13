class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len1 = pattern.size(), len2 = str.size();
        int pos1 = 0, pos2 = 0;
        auto hash = [](char c)->char{ return c - 'a'; };
        string map1[26];
        unordered_map<string, char> map2;
        while (pos1 < len1 && pos2 < len2)
        {
            char ch = pattern[pos1];
            int end = str.find(' ', pos2);
            if (end == string::npos) end = len2;
            string word = str.substr(pos2, end - pos2);
            if (map1[hash(ch)].size() == 0) map1[hash(ch)] = word;
            else if (map1[hash(ch)] != word) return false;
            if (map2.find(word) == map2.end()) map2[word] = ch;
            else if (map2[word] != ch) return false;
            pos1++;
            pos2 = end + 1;
        }
        if (pos1 < len1) return false;
        if (pos2 < len2) return false;
        return true;
    }
};
