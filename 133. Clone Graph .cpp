/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<int, UndirectedGraphNode *> constructed;
    UndirectedGraphNode *dfs_clone_node(UndirectedGraphNode *aOriNode)
    {
        UndirectedGraphNode *aNewNode = new UndirectedGraphNode(aOriNode->label);
        this->constructed[aNewNode->label] = aNewNode;
        for (UndirectedGraphNode *aNeighbor : aOriNode->neighbors)
        {
            auto it = this->constructed.find(aNeighbor->label);
            if (it != this->constructed.end())
                aNewNode->neighbors.push_back(it->second);
            else
                aNewNode->neighbors.push_back(this->dfs_clone_node(aNeighbor));
        }
        return aNewNode;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        this->constructed.clear();
        return dfs_clone_node(node);
    }
};
