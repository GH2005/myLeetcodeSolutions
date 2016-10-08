class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // the response
        vector<int> res;
        if (numCourses == 0) return res;
        res.reserve(numCourses);
        
        //
        // graph representation: O(prerequisites.size())
        //
        
        vector<int> *edges_stt_tgtIdx = new vector<int>[numCourses];
        vector<int> *edges_end_oriIdx = new vector<int>[numCourses];
        
        int *cTgts = new int[numCourses]();
        int *cOris = new int[numCourses]();
        bool *asFirst = new bool[numCourses](); // for queue initialization
        for (int i = 0; i < prerequisites.size(); i++) {
            edges_stt_tgtIdx[prerequisites[i].second].push_back(prerequisites[i].first);
            cTgts[prerequisites[i].second]++;
            edges_end_oriIdx[prerequisites[i].first].push_back(prerequisites[i].second);
            cOris[prerequisites[i].first]++;
            asFirst[prerequisites[i].first] = true;
        }
        
        //
        // try finding a directed cycle
        //
        
        int *cOris2 = new int[numCourses]();
        for (int i = 0; i < numCourses; i++) cOris2[i] = cOris[i];
        bool *closed = new bool[numCourses]();
        int node_0indeg = -1;
        for (int i = 0; i < numCourses; i++) {
            if (!closed[i] && cOris2[i] == 0) { node_0indeg = i; break; }
        }
        while (node_0indeg != -1) { // an open 0-degree node found
            for (int i = 0; i < cTgts[node_0indeg]; i++) { // every target of the 0-degree node
                cOris2[edges_stt_tgtIdx[node_0indeg][i]]--;
            }
            closed[node_0indeg] = true;
            node_0indeg = -1;
            for (int i = 0; i < numCourses; i++) {
                if (!closed[i] && cOris2[i] == 0) { node_0indeg = i; break; }
            }
        }
        // decide whether there still is an open
        for (int i = 0; i < numCourses; i++) {
            if (!closed[i]) return res;
        }
        delete[] cOris2;
        delete[] closed;
        
        //
        // bfs: O(numCourses)
        //
        
        bool *visited = new bool[numCourses]();
        // queue initialization
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {  // every node i
            if (!asFirst[i]) {
                q.push(i);
                visited[i] = true;
                res.push_back(i);
            }
        }
        delete[] asFirst;
        // run bfs
        while (q.size()) {
            int node = q.front();
            q.pop();
            // visit targets
            for (int i = 0; i < cTgts[node]; i++) { // the i-th target
                int target = edges_stt_tgtIdx[node][i];
                if (!visited[target]) {
                    bool all_oris_visited = true;
                    for (int j = 0; j < cOris[target]; j++) {   // the j-th origin of target
                        if (!visited[edges_end_oriIdx[target][j]]) {
                            all_oris_visited = false;
                            break;
                        }
                    }
                    if (all_oris_visited) {
                        q.push(target);
                        visited[target] = true;
                        res.push_back(target);
                    }
                }
            }// for: the i-th target
        }
        
        // clean and return
        delete[] edges_stt_tgtIdx;
        delete[] edges_end_oriIdx;
        delete[] cTgts, cOris;
        delete[] visited;
        return res;
    }
};
