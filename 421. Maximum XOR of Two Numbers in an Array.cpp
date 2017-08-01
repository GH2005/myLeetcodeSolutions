class Solution {
    struct TrieNode
    {
        TrieNode *next[2] = {};
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        int len = nums.size();
        // construct a trie
        TrieNode root;
        for (int value : nums)
        {
            TrieNode *curr = &root;
            for (int mask = 0x40000000; mask != 0; mask >>= 1)
            {
                int pos = (value & mask) != 0;
                TrieNode *&selected = curr->next[pos];
                if (selected == nullptr)
                    selected = new TrieNode();
                curr = selected;
            }
        }
        // go over the trie using each element
        int maxXORSofar = 0;
        for (int value : nums)
        {
            int xorValue = 0;
            TrieNode *curr = &root;
            for (int mask = 0x40000000; mask != 0; mask >>= 1)
            {
                int posDesired = (value & mask) == 0;
                if (curr->next[posDesired] == nullptr) posDesired = !posDesired;
                else xorValue |= mask;
                curr = curr->next[posDesired];
            }
            if (maxXORSofar < xorValue) maxXORSofar = xorValue;
        }
        // cleaning the trie
        return maxXORSofar;
    }
};
