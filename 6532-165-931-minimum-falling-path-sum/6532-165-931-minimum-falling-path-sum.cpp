class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int d=matrix[i][j]+dp[i+1][j];
                int dr=(j+1<n)?matrix[i][j]+dp[i+1][j+1]:INT_MAX;
                int dl=(j-1>=0)?matrix[i][j]+dp[i+1][j-1]:INT_MAX;
                dp[i][j]=min(d,min(dr,dl));
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[0][i]);
        }
        return mini;
    }
};