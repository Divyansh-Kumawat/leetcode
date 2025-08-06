class Solution {
public:
    int findpath(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0 || j>=matrix.size()) return INT_MAX;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int leftup=findpath(matrix,i-1,j-1,dp);
        int up=findpath(matrix,i-1,j,dp);
        int rightup=findpath(matrix,i-1,j+1,dp);
        return dp[i][j]=matrix[i][j]+min(leftup,min(up,rightup));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                 int left=(j > 0) ?dp[i-1][j-1]:INT_MAX;
                int down=dp[i-1][j];
                int right=(j < n-1) ?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min({left,down,right});
            }
        }

        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
        
    }
};