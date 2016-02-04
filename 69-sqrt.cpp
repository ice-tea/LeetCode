class Solution {
public:
    int mySqrt(int x) {
        int start=0;
        int end = x/2<std::sqrt(INT_MAX)? x/2+1:std::sqrt(INT_MAX);
        int mid = 0;
        while(start<=end){
            mid = (start+end)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid<x){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return (start+end)/2;
    }
};
