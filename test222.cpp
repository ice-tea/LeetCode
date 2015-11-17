#include<iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        int arr[3] = {2,3,5};
        if(num == 0)
            return false;
        for(int i=0;num!=1&&i<3;++i){
            while(num%arr[i] == 0){
                num/=arr[i];
            }
        }
        return num==1;
    }
};

int main(){
	Solution s;
	int n=14;
	if(s.isUgly(n)){
		cout<<n<<" is a ugle"<<endl;
	}
	else{
		cout<<n<<" is not a ugly"<<endl;
	}
}