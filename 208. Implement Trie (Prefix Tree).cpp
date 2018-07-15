class Trie {
  struct TrieNode
  {
    TrieNode *nexts[26] = {};
    bool isWordEnd = false;
  };
  TrieNode m_startNode;
public:
    /** Initialize your data structure here. */
    Trie() {
      
    }
  
    ~Trie(void) {
      // I know, do BFS to delete the nodes
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      TrieNode *currNode = &m_startNode;
      for (char c : word) {
        TrieNode *&nextNode = currNode->nexts[c-'a'];
        if (not nextNode) nextNode = new TrieNode;
        currNode = nextNode;
      }
      currNode->isWordEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      TrieNode *currNode = &m_startNode;
      for (char c : word) {
        TrieNode *&nextNode = currNode->nexts[c-'a'];
        if (not nextNode) return false;
        else currNode = nextNode;
      }
      return currNode->isWordEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      TrieNode *currNode = &m_startNode;
      for (char c : prefix) {
        TrieNode *&nextNode = currNode->nexts[c-'a'];
        if (not nextNode) return false;
        else currNode = nextNode;
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
