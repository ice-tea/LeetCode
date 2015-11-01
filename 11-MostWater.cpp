#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int s = height.size();
		int* ary = new int[s];
		//cout<<s<<endl;
		
		ary[0] = 0;
		int max = 0;
		int tmp = 0;
		for(int i=1;i<s;++i){
			max = 0;
			for(int j=0; j<i; j++){
				tmp = (i-j)*min(height[i],height[j]);
				if(tmp > max)
					max = tmp;
			}
			ary[i] = (ary[i-1]>max)?ary[i-1]:max;
		}
		return ary[s-1];
    }
	int min(int x, int y){
		return (x<y)?x:y;
	}
	//greedy technology
    int maxArea2(vector<int>& height) {
		int s = height.size();
		//cout<<s<<endl;
		
		int low = 0, high = s-1;
		int minH = 0, res =0;
		while(low<high){
			if(height[low]<minH)
				++low;
			else if(height[high]<minH)
				--high;
			else{
				minH = (height[low]<height[high])?height[low++]:height[high--];
				res = max(res, minH*(high-low+1));
			}
		}
		return res;
    }
};


int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(4);
	a.push_back(3);
	
	Solution s;
	int t = s.maxArea2(a);
	cout<<t<<endl;
	return 0;
}