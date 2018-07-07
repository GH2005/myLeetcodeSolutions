class Solution {
  struct Node
  {
    Node *m_nexts[26] = {};
    bool m_isWordEnd = false;
  };
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      ptrdiff_t const sz = s.size();
      
      // construct the trie
      Node *const root = new Node;
      for (std::string const &word : wordDict) {
        Node *currNode = root;
        for (char const c : word) {
          Node *&next = currNode->m_nexts[c - 'a'];
          if (not next) next = new Node;
          currNode = next;
        }
        currNode->m_isWordEnd = true;
      }
      
      // dp
      std::vector<bool> dp(sz + 1);
      dp[sz] = true;
      for (ptrdiff_t startPos = sz - 1; 0 <= startPos; --startPos) {
        Node const *currNode = root;
        for (ptrdiff_t pos = startPos; pos < sz; ++pos) {
          char c = s[pos];
          if (Node const *nextNode = currNode->m_nexts[c - 'a']) {
            currNode = nextNode;
            if (currNode->m_isWordEnd && dp[pos + 1]) { dp[startPos] = true; break; }
          }
          else { dp[startPos] = false; break; }
        }
      }
      
      // destroy the trie nodes
      
      return dp[0];
    }
};
