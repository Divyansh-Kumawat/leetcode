class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
         if (nums[0] <= target)
            dp[0][nums[0]] = true;
        for(int ind=1;ind<n;ind++){
            for(int j=1;j<=target;j++){
                bool notpick=dp[ind-1][j];
                bool pick= false;
                if(nums[ind]<=j) pick=dp[ind-1][j-nums[ind]];
                dp[ind][j]=pick||notpick;
            }
        }
        return dp[n-1][target];
    }
};