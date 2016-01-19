class Solution {
public:
    bool isHappy(int n) {
        set<int> a;
        int sum,tmp;
        while(true){
            a.insert(n);
            sum = 0;
            while(n){
                tmp = n%10;
                sum += tmp*tmp;
                n /= 10;
            }
            if(sum == 1)
                return true;
            if(a.find(sum)!=a.end())
                return false;
            n = sum;
        }
    }
};
