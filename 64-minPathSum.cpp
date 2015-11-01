class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> res;
		
		int m=grid.size();
		int n=grid[0].size();
		int tmp = 0;
		
		for(int i=n-1;i>=0;--i){
		    tmp +=grid[m-1][i];
		    res.insert(res.begin(),tmp);
		}
		tmp = 0;
		for(int i=m-2;i>=0;--i)
			for(int j=n-1;j>=0;--j){
			    if(j==n-1)
			        res[j] += grid[i][j];
			    else
			        res[j] = min(res[j+1],res[j]) + grid[i][j];
			}
		return res[0];
    }
};
