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
