#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());  
    vector<vector<int> > result;  
    int len = nums.size();  
    for(int i =0; i< len; i++)  
    {  
		if(i > 0 &&  nums[i] ==  nums[i-1])continue;
        int target = 0-nums[i];
        int start = i+1, end =len-1;  
        while(start<end)  
        {  
            if(nums[start] + nums[end] == target)  
            {  
                vector<int> solution;  
                solution.push_back(nums[i]);  
                solution.push_back(nums[start]);  
                solution.push_back(nums[end]);  
                result.push_back(solution);  
                start++; end--;  
                while(start<end && nums[start] == nums[start-1]) start++;  
                while(start<end && nums[end] == nums[end+1]) end--;  
            }  
            else if(nums[start] + nums[end] < target)  
            {  
                start++;  
            }  
            else  
            {  
                end--;  
            }  
        }  
        if(i<len-1)  
        {  
            while(nums[i] == nums[i+1]) i++;  
        }  
    }  
    return result;  
    }  
};

void print(vector<int> v){
	for(vector<int>::iterator i=v.begin();i!=v.end();++i){
		printf("%d  ",*i);
	}
	printf("\n");
}

void print2(vector<vector<int> > v){
	for(vector<vector<int> >::iterator i=v.begin();i!=v.end();++i){
		print(*i);
	}
	printf("\n");
}

class Solution2 {
public:
    vector<vector<int> > threeSum(vector<int> & nums) {
        int n =  nums.size();
        sort( nums.begin(),  nums.end());
        vector<vector<int> > res;
        for(int i = 0; i < n-2; i++)
        {
            if(i > 0 &&  nums[i] ==  nums[i-1])continue;//重复的元素不用计算
            int target2 = 0 -  nums[i];
            twoSum( nums, i+1, target2, res);
        }
        return res;
    }
    void twoSum(vector<int> &sortednums, int start, int target, vector<vector<int> >&res)
    {
        int head = start, tail = sortednums.size() - 1;
        while(head < tail)
        {
            int tmp = sortednums[head] + sortednums[tail];
            if(tmp < target)
                head++;
            else if(tmp > target)
                tail--;
            else
            {
                vector<int> solution;  
                solution.push_back(sortednums[start-1]);  
                solution.push_back(sortednums[head]);  
                solution.push_back(sortednums[tail]);  
                res.push_back(solution);
                //res.push_back(vector<int>{sortednums[start-1], sortednums[head], sortednums[tail]});
				//为了防止出现重复的二元组，使结果等于target
				int k = head+1;
                while(k < tail && sortednums[k] == sortednums[head])k++;
                head = k;
                
                k = tail-1;
                while(k > head && sortednums[k] == sortednums[tail])k--;
                tail = k;
            }
        }
    }
};

int main(){
	vector<int> nums;
	nums.push_back(-6);
	nums.push_back(4);
	nums.push_back(2);
	Solution s;
	vector <vector<int> > res = s.threeSum(nums);
	print2(res);
}