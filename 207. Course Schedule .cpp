class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 0) return true;
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
        int remaining = numCourses;
        while (!q.empty())
        {
            int course = q.front(); q.pop();
            remaining --;
            for (int tgtCourse : adjTable[course])
                if (--indegs[tgtCourse] == 0) q.push(tgtCourse);
        }
        return remaining == 0;
    }
};
