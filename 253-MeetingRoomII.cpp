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
    static bool compare(Interval& i1, Interval &i2){
        return i1.start<i2.start ||(i1.start==i2.start && i1.end<i2.end);
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        if(intervals.size()==0)
            return 0;
        
        int maxL = 1;
        priority_queue<int, std::vector<int>, std::greater<int> > ends;
        for(int i=0;i<intervals.size();++i){
            while(!ends.empty()){
                cout<<ends.top()<<endl;
                if(intervals[i].start>=ends.top()){
                    ends.pop();
                    continue;
                }
                else{
                    break;
                }
            }
            ends.push(intervals[i].end);
            maxL = max(maxL,(int)ends.size());
        }
        return maxL;
    }
};
