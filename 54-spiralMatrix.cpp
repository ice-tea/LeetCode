#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
		int i=1;
		while(size(matrix)>0)
			sprialHelp(matrix, res,i++%4);
		print(res);
		return res;
    }
	int size(vector<vector<int> > &matrix){
		int i=0;
		for(int j=0;j<matrix.size();j++){
			i+=matrix[j].size();
		}
		return i;
	}
	void sprialHelp(vector<vector<int> >& matrix,vector<int> &res,int i){
		vector<int> tmp;
		switch(i){
			case 0:
				for(int j=matrix.size()-1;j>=0;j--){
					tmp.push_back(matrix[j][0]);
					matrix[j].erase(matrix[j].begin());
				}
				for(int j=0;j<tmp.size();j++){
					res.push_back(tmp[j]);
				}
				break;
			case 1: 
				tmp = matrix[0];
				matrix.erase (matrix.begin());
				for(int j=0;j<tmp.size();j++){
					res.push_back(tmp[j]);
				}
				
				break;
			case 2:
				for(int j=0;j<matrix.size();j++){
					tmp.push_back(matrix[j][matrix[j].size()-1]);
					matrix[j].pop_back();
				}
				for(int j=0;j<tmp.size();j++){
					res.push_back(tmp[j]);
				}
				break;
			case 3:
				tmp = matrix[matrix.size()-1];
				matrix.pop_back();
				for(int j=tmp.size()-1;j>=0;j--){
					res.push_back(tmp[j]);
				}
				break;
		}
	}
	
	void print(vector<int> nums){
		int s = nums.size();
		for(int i=0;i<s;++i){
			cout<<nums[i]<<"\t";
		}
		cout<<endl;
	}
};


int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	
	vector<int> b;
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	
	vector<int> c;
	c.push_back(3);
	c.push_back(4);
	c.push_back(5);
	c.push_back(6);
	
	vector<vector<int> > m;
	m.push_back(a);
	m.push_back(b);
	m.push_back(c);
	Solution s;
	s.spiralOrder(m);
	return 0;
}