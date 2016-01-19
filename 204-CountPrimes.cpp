class Solution {
public:
    int countPrimes(int n) {
        int * arr =  new int[n];
        for(int i=0;i<n;i++){
            arr[i] = i+1;
        }
        if(n==1)
            return 0;
        arr[0] = -1;
        arr[1] = -1;
        for(int i=2; i<n;i++){
            if(arr[i] ==-1)
                continue;
            for(int j=2; i*j<n; ++j)
                arr[i*j] = -1;
        }
        int res=0;
        for(int i=2; i<n;i++){
            if(arr[i] ==-1)
                continue;
            res++;
        }
        return res;
    }
};
