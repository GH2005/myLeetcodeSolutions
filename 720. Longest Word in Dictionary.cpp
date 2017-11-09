class Solution {
public:
    struct TrieNode
    {
        TrieNode *nextViaChar[26] = {};
        bool isEndOfWord = false;
    };
    string longestWord(vector<string>& words) {
        // construct a trie
        TrieNode base;
        for (string &word : words)
        {
            TrieNode *curr = &base;
            for (char c : word)
            {
                TrieNode *&next = curr->nextViaChar[c - 'a'];
                if (next == nullptr) next = new TrieNode();
                curr = next;
            }
            // mark the last node as end-of-word
            curr->isEndOfWord = true;
        }
        // find the longest word
        string longestWord, stk;
        int maxLenSofar = 0;
        this->dfs(&base, longestWord, stk, maxLenSofar, 0);
        // free TrieNodes
        return longestWord;
    }
    void dfs(TrieNode *node, string &longestWord, string &stk,
    int &maxLenSofar, int len)
    {
        bool isLeaf = true;
        for (int ch = 0; ch < 26; ch++)
        {
            TrieNode *&next = node->nextViaChar[ch];
            if (next != nullptr && next->isEndOfWord)
            {
                isLeaf = false;
                stk.push_back(ch + 'a');
                dfs(next, longestWord, stk, maxLenSofar, len+1);
                stk.pop_back();
            }
        }
        if (isLeaf && len > maxLenSofar)
        {
            maxLenSofar = len;
            longestWord = stk;
        }
    }
};
