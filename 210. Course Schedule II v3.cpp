class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses <= 0) return res;
        vector<int> indegs(numCourses);
        vector<vector<int>> adjTable(numCourses);
        // construct adjTable and the in-degree of every node
        for (pair<int, int> &p : prerequisites)
        {
            adjTable[p.second].push_back(p.first);
            indegs[p.first]++;
        }
        // initialize queue
        queue<int> q;
        for (int c = 0; c < numCourses; c++)
            if (indegs[c] == 0) q.push(c);
        // visit the node whose in-degree is zero
        while (!q.empty())
        {
            int course = q.front(); q.pop();
            res.push_back(course);
            for (int tgtCourse : adjTable[course])
                if (--indegs[tgtCourse] == 0) q.push(tgtCourse);
        }
        if (res.size() < numCourses) res.clear();
        return res;
    }
};
