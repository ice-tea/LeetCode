#include<iostream>
#include<vector>
using namespace std;


struct Interval {
 	int start;
    int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct myInterval{
	int num;
	bool left;
	myInterval(int n, bool b): num(n), left(b) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<myInterval> v;
		for(int i=0;i<intervals.size();++i){
			v.push_back(myInterval(intervals[i].start,true));
			v.push_back(myInterval(intervals[i].end,false));
		}
		sort(v.begin(),v.end(),acompare);

		int l = 0;
		Interval tmp;
		vector<Interval> res;
		for(int i=0;i<v.size();++i){
			if(l==0)
				tmp.start = v[i].num;
			if(v[i].left)
				l++;
			else
				l--;
			if(l==0){
				tmp.end = v[i].num;
				res.push_back(tmp);
			}
		}
		
        return res;
    }
    
	static bool acompare(myInterval lhs, myInterval rhs) { return lhs.num < rhs.num ||(lhs.num==rhs.num&&lhs.left&&!rhs.left); }
	
	void print(vector<myInterval> m){
		int s = m.size();
		for(int i=0;i<s;++i){
			if(m[i].left)
				cout<<"[  at"<<m[i].num<<"\t";
			else
				cout<<"]  at"<<m[i].num<<"\t";
		}
		cout<<endl;
	}
};

//------------------

bool IntervalCompare(Interval a, Interval b){
	return a.start < b.start;
}

class Solution2 {
	public:
		vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
		if(intervals.size() == 0) return result;
		sort(intervals.begin(), intervals.end(), IntervalCompare);
		result.push_back(intervals[0]);
		for(int i=1; i<intervals.size(); i++){
			if(intervals[i].start <= result.back().end) result.back().end = max(intervals[i].end, result.back().end);
            else result.push_back(intervals[i]);
        }
        return result;
	}
	
	vector<Interval> myinsert(vector<Interval>& intervals, Interval newInterval) {
		
		Interval tmp(newInterval.start, newInterval.end);
		int size=intervals.size();
		int i=0,j=0, pos=0;
		bool found = false;
		
		while(i<size){
			if(intervals[j].start<=newInterval.start && intervals[j].end >= newInterval.start){
				found = true;
				pos = j;
				break;
				//intervals.erase(intervals.begin()+j);
			}
			else if(intervals[j].start>newInterval.start && intervals[j].end < newInterval.end){
				intervals[j].start = newInterval.start;
				pos = j;
				found = true;
				break;
				//intervals.erase(intervals.begin()+j);
			}
			else if(intervals[j].start<=newInterval.end && intervals[j].end >= newInterval.end){
				tmp.end = intervals[j].end;
				found = true;
				break;
				//intervals.erase(intervals.begin()+j);
			}
			else if(intervals[j].start > newInterval.end){
				break;
			}
			else
				++j;
			++i;
		}
		if(!found){
			if(j==size){
				intervals.push_back(tmp);
			}
			else{
				intervals.insert(intervals.begin()+j,tmp);
			}
			return intervals;
		}
		if(found){
			
			while(i<size){
				if(intervals[j].start>newInterval.start && intervals[j].end < newInterval.end){
					intervals.erase(intervals.begin()+j);
				}
				else if(intervals[j].start<=newInterval.end && intervals[j].end >= newInterval.end){
					tmp.end = intervals[j].end;
					break;
					//intervals.erase(intervals.begin()+j);
				}
				else if(intervals[j].start > newInterval.end){
					break;
				}
				else
					++j;
				++i;
			}
		}
		
		return intervals;
	}
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

//------------------

void print(vector<Interval>nums){
	int s = nums.size();
	for(int i=0;i<s;++i){
		cout<<"<"<<nums[i].start<<"  "<<nums[i].end<<">"<<"\t";
	}
	cout<<endl;
}

void test1(){
	Interval a(1,2);
	Interval b(3,5);
	Interval c(6,7);
	Interval d(8,10);
	
	Interval e(8,10);
	
	
	vector<Interval> intervals;
	intervals.push_back(a);
	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	intervals.push_back(e);
	print(intervals);
	Solution s;
	print(s.merge(intervals));
}

void test2(){
	Interval a(1,2);
	Interval b(3,5);
	Interval c(6,7);
	Interval d(8,10);
	Interval e(12,16);
	
	Interval f(4,9);
	
	
	vector<Interval> intervals;
	intervals.push_back(a);
	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	//intervals.push_back(e);
	print(intervals);
	Solution2 s;
	print(s.insert(intervals, f));
}
int main(){
	test2();
	return 0;
}