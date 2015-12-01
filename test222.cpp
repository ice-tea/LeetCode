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
    int maxProduct(vector<int>& nums) {
        vector<int> res;
        int mul=1;
        int maxP = nums[0];
        for(int i=0;i<nums.size();i++){
            mul*=nums[i];
            maxP = max(maxP,mul);
            res.push_back(mul);
            if(nums[i]==0)
                mul = 1;
        }
        int s;
		print(res);
		s=res.size();
        while(s>0){
            if(res[0]==0){
                res.erase(res.begin(),res.begin()+1);
                continue;
            }
            for(int i=1;i<s && res[i]!=0;++i){
                res[i]/=res[0];
				cout<<"res[]"<<i<<":"<<res[i]<<endl;
                maxP = max(maxP,res[i]);
            }
            res.erase(res.begin(),res.begin()+1);
			s=res.size();
        }
        return maxP;
    }
};


int main(){
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(4);
	//nums.push_back(1);
	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(2);
	Solution s;
	cout<< s.maxProduct(nums);
}