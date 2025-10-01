class Solution {
public:
    int maxmoney(vector<int> & nums,int n,vector<int> dp){
        if(n==0 || n==1) return nums[n];
        if(dp[n]!=-1) return dp[n];
        int notrob=maxmoney(nums,n-1,dp);
        int rob;
        if(n>1) rob=maxmoney(nums,n-2,dp)+nums[n];
        return dp[n]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return maxmoney(nums,n-1,dp);
    }
};