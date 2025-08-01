class Solution {
public:
    int ans(int n,vector<int>& dp){
        if(n==1 || n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=ans(n-1,dp)+ans(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ans(n,dp);
    }
};