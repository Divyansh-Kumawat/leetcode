class Solution {
public:
    int findmin(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        
        if(j==triangle.size()-1) return triangle[j][i];
        if(dp[i][j]!=-1) return dp[i][j];

        int first=findmin(i,j+1,triangle,dp);
        int second=findmin(i+1,j+1,triangle,dp);

        return dp[i][j]=triangle[j][i]+min(first,second);


       
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }

};