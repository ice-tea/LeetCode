class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=gas.size();
        int r=0;
        int i=0,j=0;
        int tmp;

        while(i<s){
            j = 0;
            r = 0;
            while(j<s){
                tmp = gas[(i+j)%s]-cost[(i+j)%s];
                if(r + tmp < 0)
                    break;
                r += tmp;
                ++j;
            }
            if(j==s)
                return i;
            i+=(j>0)?j:1;
        }
        return -1;
    }
};
/*
i++ time..
i+=j? ensure?
*/
