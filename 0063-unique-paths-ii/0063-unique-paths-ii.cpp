class Solution {
public:
    int ways(int n,int m,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(n<0 || m< 0) return 0;
        if(obstacleGrid[n][m]==1) return 0;
        if(n==0 && m==0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        int up=ways(n-1,m,obstacleGrid,dp);
        int left=ways(n,m-1,obstacleGrid,dp);
        return dp[n][m]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return ways(n-1,m-1,obstacleGrid,dp);
    }
};