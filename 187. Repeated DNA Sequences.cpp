class Solution {
private:
    struct Node {
        typedef Node* NodePtr;
        NodePtr next[4] = {};
        int cOccur = 0; // only for a node of level-9
    };
    /*void CleanNodes(Node *n) {
        for (int i = 0; i < 4; i++) {
            if (n->next[i] != nullptr) CleanNodes(n->next[i]);
        }
        delete n;
    }*/
    inline int GetIndex(char c) {
        switch(c) {
          case 'A': return 0;
          case 'C': return 1;
          case 'G': return 2;
          case 'T': return 3;
          default: assert(false);
        };
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // preparations
        int sz = s.size();
        
        // response
        vector<string> res;
        if (sz <= 10) return res;
        res.reserve((sz-10)/2);
        
        // go over string s and fill vector<string> res
        Node *begin = new Node();
        for (int i = 0; i < sz - 10 + 1; i++) { // string s[i, i+10)
            Node *currNode = begin;
            for (int j = 0; j < 10; j++) { // char s[i+j]
                Node *&thePtr = currNode->next[GetIndex(s[i+j])];
                if (thePtr == nullptr) thePtr = new Node();
                currNode = thePtr;
            }
            currNode->cOccur ++;
            // add the string to vector<string>_res if it occurs the second time
            if (currNode->cOccur == 2) {
                res.push_back(s.substr(i, 10));
            }
        }// string s[i, i+10)
        
        // clean and return
        // CleanNodes(begin);
        return res;
    }
};
