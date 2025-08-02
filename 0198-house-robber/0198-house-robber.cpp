class Solution {
public:
    int find(vector<int> & nums,int i,vector<int>& dp){
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+find(nums,i-2,dp);
        int notpick=find(nums,i-1,dp);
        
        return dp[i]=max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return find(nums,n-1,dp);
    }
};