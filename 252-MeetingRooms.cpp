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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0)
            return true;
        vector<int> cur;
        int pos = 0;
        for(int i=0;i<intervals.size();++i){
            for(pos=0;pos<cur.size();pos+=2){
                if(intervals[i].start<cur[pos]){
                    if(intervals[i].end>cur[pos])
                        return false;
                    else
                        break;
                }
                if(intervals[i].start<cur[pos+1])
                    return false;
            }
            cur.insert(cur.begin()+pos,intervals[i].start);
            cur.insert(cur.begin()+pos+1,intervals[i].end);
        }
        return true;
    }
};
