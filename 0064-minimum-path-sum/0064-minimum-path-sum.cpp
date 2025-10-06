class Solution {
public:
    int minpath(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return INT_MAX;
        if(dp[n][m]!=-1) return dp[n][m];
        int up=minpath(n-1,m,grid,dp);
        int left=minpath(n,m-1,grid,dp);
        return dp[n][m]=grid[n][m]+min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else {
                    int left=grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else left+=1e9;

                    int up=grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e9;
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};