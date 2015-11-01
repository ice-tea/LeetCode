class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
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
};
