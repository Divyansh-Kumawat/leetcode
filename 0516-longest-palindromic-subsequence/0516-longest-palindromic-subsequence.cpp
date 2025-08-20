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
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // every single character is a palindrome of length 1
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        // fill table from shorter substrings to longer
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (len == 2 ? 0 : dp[i+1][j-1]);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};