class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

         vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0; 
                else if (i == 0 && j == 0) {
                    dp[i][j] = 1; // Base case, already set
                } else{
                    int left= (i>0)?dp[i-1][j]:0;
                    int right=(j>0)?dp[i][j-1]:0;
                    dp[i][j]=left+right;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};