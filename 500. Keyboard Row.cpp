class Solution {
    char hashTable[26] = { 1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1,
        1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2 };
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        auto get_row = [](char *table, char ch)->char
        {
            if (ch < 'a') ch += 'a' - 'A';
            return table[ch - 'a'];
        };
        for (string &word : words)
        {
            if (word.size() <= 1) res.push_back(word);
            else
            {
                int pos = 1;
                while (pos < word.size())
                {
                    if (get_row(this->hashTable, word[pos-1])
                       != get_row(this->hashTable, word[pos]))
                        break;
                    pos ++;
                }
                if (word.size() == pos) res.push_back(word);
            }
        }
        return res;
    }
};
