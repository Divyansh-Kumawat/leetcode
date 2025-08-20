class Solution {
public:
    // int lps(int i,int j,string s,vector<vector<int>>& dp){
    //     if(i==j) return 1;
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j]) return  dp[i][j]=2+lps(i+1,j-1,s,dp);
    //     return dp[i][j]=max(lps(i+1,j,s,dp),lps(i,j-1,s,dp));
    // }
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(temp.begin() , temp.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==temp[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};