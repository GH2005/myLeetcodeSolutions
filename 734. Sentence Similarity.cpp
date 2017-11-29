class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int wordCount1 = words1.size(), wordCount2 = words2.size();
        if (wordCount1 != wordCount2) return false;
        if (wordCount1 == 0) return true;
        unordered_set<string> uoset;
        for (auto &pr : pairs) uoset.insert(pr.first + '#' + pr.second); // the idea of using '#' got from editorial
        for (int pos = 0; pos < wordCount1; pos++)
        {
            string &word1 = words1[pos], &word2 = words2[pos];
            if (word1 == word2) continue;
            if (uoset.find(word1 + '#' + word2) != uoset.end()) continue;
            if (uoset.find(word2 + '#' + word1) == uoset.end()) return false;
        }
        return true;
    }
};
