class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        const int len = people.size();
        vector<pair<int, int>> res;
        if (len == 0) return res;
        res.reserve(len);
        auto person_comp = [](const pair<int, int> &p1, const pair<int, int> &p2)->bool
        {
            if (p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        };
        sort(people.begin(), people.end(), person_comp);
        // insertion sort
        for (auto &person : people)
        {
            int rmngOccurs = person.second;
            const int height = person.first;
            auto is_place_to_insert = [&rmngOccurs, height](const auto &ele)->bool
            {
                if (rmngOccurs == 0) return true;
                if (ele.first >= height) rmngOccurs--;
                return false;
            };
            auto foundIt = find_if(res.begin(), res.end(), is_place_to_insert);
            res.insert(foundIt, person);
        }
        return res; // move sementic
    }
};
