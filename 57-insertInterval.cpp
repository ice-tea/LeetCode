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
         vector<Interval> res;
	        int index = 0;
	        while(index < intervals.size() && intervals[index].end < newInterval.start){
	            res.push_back(intervals[index++]);
	        }
	        while(index < intervals.size() && intervals[index].start <= newInterval.end){
	            newInterval.start = min(newInterval.start, intervals[index].start);
	            newInterval.end = max(newInterval.end, intervals[index].end);
	            index++;
	        }
	        res.push_back(newInterval);
	        while(index < intervals.size()){
	            res.push_back(intervals[index++]);
	        }
	        return res;
    }
};
