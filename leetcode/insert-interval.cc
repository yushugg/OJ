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
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    Interval overlap;
    overlap.start = newInterval.start;
    bool lapFinished = false;
    for (auto iter = intervals.begin(); iter != intervals.end(); ++iter) {
      if (lapFinished) result.push_back(*iter);
      else {
        if (newInterval.end < iter->start) {
          // os oe is ie
          lapFinished = true;
          overlap.end = newInterval.end;
          result.push_back(overlap);
          result.push_back(*iter);
        } else if (newInterval.start < iter->start && newInterval.end >= iter->start && newInterval.end <= iter->end) {
          // os is oe ie
          lapFinished = true;
          overlap.end = iter->end;
          result.push_back(overlap);
        } else if (newInterval.start >= iter->start && newInterval.end <= iter->end) {
          // is os oe ie
          lapFinished = true;
          overlap.start = iter->start; overlap.end = iter->end;
          result.push_back(overlap);
        } else if (newInterval.start >= iter->start && newInterval.start <= iter->end && newInterval.end > iter->end) {
          // is os ie oe
          overlap.start = iter->start;
        } else if (newInterval.start > iter->end) {
          // is ie os oe
          result.push_back(*iter);
        }
      }
    }
    if (!lapFinished) { overlap.end = newInterval.end; result.push_back(overlap); }

    return result;
  }
};
