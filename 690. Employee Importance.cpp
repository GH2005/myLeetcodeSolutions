/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee *> uomap;
        for (auto p : employees) uomap[p->id] = p;
        auto it = uomap.find(id);
        if (it == uomap.end()) return 0;
        // breadth-first search
        int total = 0;
        queue<Employee *> q;
        q.push(it->second);
        while (!q.empty())
        {
            Employee *pe = q.front(); q.pop();
            total += pe->importance;
            for (int sub : pe->subordinates)
                q.push(uomap[sub]);
        }
        return total;
    }
};
