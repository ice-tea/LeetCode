class Solution {
public:
    int climbStairs(int n) {
        int nums[2] ={1,2};
        if(n<3)
            return nums[n-1];
        int i = 3;
        while(i<=n){
            nums[(i+1)%2] = nums[0] + nums[1];
            ++i;
        }
        return nums[(n+1)%2];
    }
	int climbStairs2(int n) {
	    if(n<4)return n;
	    int a=2,b=3,c=5;
	    n -= 4;
	    while(n--){
	        a=c;
	        c=b+c;
	        b=a;
	    }
	    return c;
	}
};