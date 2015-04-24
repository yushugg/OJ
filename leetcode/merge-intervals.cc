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
    vector<Interval> result;
    if (intervals.empty()) return result;
    // Sort
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b)->bool {
      return a.start < b.start;
    });

    // Add to result
    Interval temp;
    temp.start = intervals[0].start; temp.end = intervals[0].end;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start > temp.end) { result.push_back(temp); temp = intervals[i]; }
      else { temp.start = min(intervals[i].start, temp.start); temp.end = max(intervals[i].end, temp.end); }
    }
    result.push_back(temp);

    return result;
  }
};
