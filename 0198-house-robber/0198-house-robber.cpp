class Solution {
public:
    int maxmoney(vector<int> & nums,int n,vector<int>& dp){
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int rob=maxmoney(nums,n-2,dp)+nums[n];
        int notrob=maxmoney(nums,n-1,dp);
        
        return dp[n]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return maxmoney(nums,n-1,dp);
    }
};