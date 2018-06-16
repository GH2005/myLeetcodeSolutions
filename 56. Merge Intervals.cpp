/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
      std::map<int const, std::pair<size_t, size_t>> ordered; //first == #start_points, second == $end_points
      for (Interval const &interval : intervals) {
        ++ordered[interval.start].first;
        ++ordered[interval.end].second;
      }
      vector<Interval> res;
      int mergedStart;
      size_t pile = 0;
      for (auto const &ele : ordered) {
        if (pile == 0) { mergedStart = ele.first; }; 
        pile += ele.second.first;
        pile -= ele.second.second;
        if (pile == 0) { res.emplace_back(mergedStart, ele.first); };
      }
      return res;
    }
};
