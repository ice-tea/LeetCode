#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
		for(int i=0;i<101;++i)
			for(int j=0;j<101;++j){
				dp[i][j] = 1;
			}
		
		
		for(int i=m-2;i>=0;--i)
			for(int j=n-2;j>=0;--j){
				dp[i][j] = dp[i+1][j] + dp[i][j+1];
				//cout<<i<<j<<dp[i][j]<<endl;
			}
		
		return dp[0][0];
    }
	
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
		int dp[101][101] = {{0}};
		
				int m=obstacleGrid.size();
				int n=obstacleGrid[0].size();
				dp[m-1][n] = 1;
				for(int i=m-1;i>=0;--i)
					for(int j=n-1;j>=0;--j){
					    if(obstacleGrid[i][j])
					        dp[i][j] = 0;
					    else
						    dp[i][j] = dp[i+1][j] + dp[i][j+1];
						//cout<<i<<j<<dp[i][j]<<endl;
					}
		
				return dp[0][0];
	}
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

int main(){
    Solution s;
 
    //print(a1);
    cout<<(s.uniquePaths(3, 4));
	return 0;
}