class Solution {
  struct Node
  {
    Node *m_nexts[26] = {};
    bool m_isWordEnd = false;
  };
  Node const *m_root;
  std::string const *m_str;
  bool prv_backtracking(ptrdiff_t const startPos) const noexcept {
    Node const *currNode = m_root;
    
    for (ptrdiff_t pos = startPos; pos < m_str->size(); ++pos) {
      char c = m_str->at(pos);
      if (Node const *nextNode = currNode->m_nexts[c - 'a']) {
        currNode = nextNode;
        if (currNode->m_isWordEnd && prv_backtracking(pos + 1)) { return true; }
      }
      else { return false; }
    }
    
    return currNode->m_isWordEnd;
  }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
      m_root = root;
      m_str = &s;
      
      // search for a valid set of word breaks
      return prv_backtracking(0);
      
      // destroy the trie nodes
    }
};
