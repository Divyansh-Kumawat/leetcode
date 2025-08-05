class Solution {
public:
    int paths(int m,int n,vector<vector<int>>& dp){
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int left= paths(m-1,n,dp);
        int right = paths(m,n-1,dp);
        dp[m][n]=left+right;
        return dp[m][n];
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i == 0 && j == 0) {
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