// trie solution, memory limit exceeded
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        struct TrieNode
        {
            TrieNode *nextFrom[128] = {};
            int index = -1;
        };
        // construct the trie for list1
        TrieNode startNode;
        for (int pos = 0; pos < list1.size(); pos++)
        {
            string &rest = list1[pos];
            TrieNode *curr = &startNode;
            for (char c : rest)
            {
                TrieNode *&next = curr->nextFrom[c];
                if (next == nullptr) next = new TrieNode();
                curr = next;
            }
            curr->index = pos;
        }
        // walk through list2 and add strings with smallest sum
        vector<string> res;
        int minSumSofar = INT_MAX;
        for (int pos = 0; pos < list2.size(); pos++)
        {
            TrieNode *curr = &startNode;
            for (char c : list2[pos])
            {
                if (curr->nextFrom[c] == nullptr) goto end_iteration;
                else curr = curr->nextFrom[c];
            }
            if (curr->index != -1)
            {
                int sum = curr->index + pos;
                if (sum < minSumSofar) res.clear(), minSumSofar = sum;
                if (sum == minSumSofar) res.push_back(list2[pos]);
            }
            end_iteration:;
        }
        // clean the TrieNodes
        queue<TrieNode *> q;
        for (int i = 0; i < 128; i++)
            if (startNode.nextFrom[i] != nullptr)
                q.push(startNode.nextFrom[i]);
        while (!q.empty())
        {
            TrieNode *node = q.front();
            q.pop();
            for (int i = 0; i < 128; i++)
                if (node->nextFrom[i] != nullptr)
                    q.push(node->nextFrom[i]);
            delete node;
        }
        return res;
    }
};
