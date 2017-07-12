class Solution {
    vector<int> indegs;
    class Comp
	{
		Solution *aSol;
	public:
		Comp(Solution *a) : aSol(a) {}
		bool operator () (const int &course1, const int &course2) const
		{
			return aSol->indegs[course1] > aSol->indegs[course2];
		}
	};
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses <= 0) return res;
        this->indegs = vector<int>(numCourses);
        vector<vector<int>> adjTable(numCourses);
        // construct adjTable and the in-degree of every node
        for (pair<int, int> &p : prerequisites)
        {
            adjTable[p.second].push_back(p.first);
            this->indegs[p.first]++;
        }
        // initialize heap
        vector<int> heap(numCourses);
        for (int pos = 0; pos < numCourses; pos++) heap[pos] = pos;
        std::make_heap(heap.begin(), heap.end(), Solution::Comp(this));
        // visit the node whose in-degree is zero
        while (!heap.empty())
        {
            int course = heap[0];
            std::pop_heap(heap.begin(), heap.end(), Solution::Comp(this));
            heap.pop_back();
            if (this->indegs[course] > 0) break;
            res.push_back(course);
            for (int tgtCourse : adjTable[course])
                this->indegs[tgtCourse]--;
            std::make_heap(heap.begin(), heap.end(), Solution::Comp(this));
        }
        // decide the res
        if (heap.empty()) return res;
        else return vector<int>();
    }
};
