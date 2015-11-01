#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool canJump3(vector<int>& nums) {
	        int s = nums.size();
	        int m = 0;
	        for(int i=0;i<s && i<m+1;++i){
	            m = max(m,i+nums[i]);
	            if(m>=s-1)
	                return true;
	        }
			return false;
	    }
	
    bool canJump(vector<int>& nums) {
        int s = nums.size();
        nums[s-1] = 1;
		bool can = false;
        for(int i=s-2;i>=0;--i){
			can = false;
            for(int j=1;j<=nums[i] &&i+j<=s-1;j++){
                if(nums[i+j] == 1){
                    can = true;
                    break;
                }
            }
			nums[i] = can;
        }
        return nums[0]==1;
    }
	int max(int i,int j){
		return i>j?i:j;
	}
    bool canJump2(vector<int>& nums) {
        int s = nums.size();
				cout<<s;
		print(nums);
        nums[s-1] = 1;
        for(int i=s-2;i>=0;--i){
			cout<<"checking"<<i<<"  "<<nums[i]<<endl;
            for(int j=1;j<=nums[i] &&i+j<=s-1;j++){
				cout<<"check"<<i<<"plus"<<j<<endl;
                if(nums[i+j] == 1){
                    nums[i] =1;
                    break;
                }
                nums[i] = 0;//this assingment is too soon
            }
        }
		print(nums);
        return nums[0]==1;
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
	a.push_back(2);
	a.push_back(0);
	a.push_back(0);

	Solution s;
	if(s.canJump3(a)){
		cout<<"yes"<<endl;
	}
	else
		cout<<"no"<<endl;
	return 0;
}