class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len=nums.size();
        map<int,int> possibles;
        map<int,int> increase;
        
        for(int i=0;i<len;++i){
            increase.clear();
            for(auto n:possibles){
                if(possibles.find(n.first+nums[i]) != possibles.end())
                    possibles[n.first+nums[i]] = min(possibles[n.first]+1, possibles[n.first+nums[i]]);
                else
                    increase[n.first+nums[i]] = possibles[n.first]+1;
            }
            possibles.insert(increase.begin(), increase.end());
            possibles[nums[i]] = 1;
        }
        return (possibles.find(s)==possibles.end())?0:possibles[s];
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = nums.size();
        bfs(s,nums,0,0,minLen);
        return minLen;
    }
    void bfs(int t, vector<int>& nums, int pos,int tmp, int& minL){
        //cout<<t<<endl;
        if(t==0){
            minL = min(minL,tmp);
            return;
        }
        if(t<0 || pos==nums.size())
            return;
        bfs(t-nums[pos],nums,pos+1,tmp+1,minL);
        bfs(t,nums,pos+1,tmp,minL);
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int posi=0,posj=0;
        int sum = 0;
        int minLen = nums.size()+1;
        while(posj<len){
            sum += nums[posj];
            if(sum>=s){
                while(sum >= s &&posi<=posj){
                    sum -= nums[posi];
                    posi++;
                }
                minLen = min(minLen, posj-posi+2);
            }
            posj++;
        }
        return (minLen==nums.size()+1)?0:minLen;
            
    }
};
