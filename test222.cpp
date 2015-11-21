#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
	for(vector<int>::iterator i=v.begin();i!=v.end();++i){
		printf("%d  ",*i);
	}
	printf("\n");
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> tmp =nums;
		print(tmp);
        int s;
        int i;
        s=tmp.size();
        while(s>1){
            for(i=0;i<s;i=i+2){
                if(i+1<s && tmp[i]==tmp[i+1])
                    tmp.push_back(tmp[i]);
                else if(i+1==s)
                    tmp.push_back(tmp[s-1]);
            }
			print(tmp);
            tmp.erase(tmp.begin(),tmp.begin()+s);
            s=tmp.size();
			print(tmp);
        }
        return tmp[0];
    }
};


int main(){
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	Solution s;
	cout<< s.majorityElement(nums);
}