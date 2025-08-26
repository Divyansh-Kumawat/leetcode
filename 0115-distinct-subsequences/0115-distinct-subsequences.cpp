class Solution {
public:
    // int nlcs(int i,int j,string s,string t,vector<vector<int>> dp){
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]){
    //         return dp[i][j]=nlcs(i-1,j-1,s,t,dp)+nlcs(i-1,j,s,t,dp);
    //     }
    //     else{
    //         return dp[i][j]=nlcs(i-1,j,s,t,dp);
    //     }
    // }
    int numDistinct(string s, string t) {
        int n = s.size();
    int m = t.size();
    // dp[i][j] = number of subsequences of s[0..i-1] that equals t[0..j-1]
    vector<vector<double>> dp(n+1, vector<double>(m+1, -1));

    // Base cases
    for (int i = 0; i <= n; i++) dp[i][0] = 1;  // Empty t can always be formed
    for (int j = 1; j <= m; j++) dp[0][j] = 0;  // Non-empty t cannot be formed from empty s

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) 
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];  
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    return (int)dp[n][m];
    }
};