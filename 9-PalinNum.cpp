

class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0)
			return false;
		int max =1;
		int bits = 1;
		int tmp =x/10;
		while(tmp>0){
			tmp/=10;
			max*=10;
			bits++;
		}
		printf("%d  %d   %d\n",x,max,bits);
		while(bits>1){
			if(x%10!=(x/max)%10)
				return false;
			max/=100;
			x/=10;
			bits-=2;
			printf("%d  %d   %d\n",x,max,bits);
		}
		printf("%d",max);
        return true;
    }
	bool isPalindrome2(int x) {  
		if(x<0) return false;  
		int div = 1;  
		while(x/div >=10)  
		    div*=10;  
		while(x>0){  
		     int l = x/div;  
		     int r = x%10;  
		     if(l!=r) return false;  
		     x=x%div/10;  
		     div/=100;  
		}  
		return true;
	}  
};


int main(){
	Solution s;
	if(s.isPalindrome(1000000001))
		printf("yes!");
	else
		printf("no!");
}