class Solution {
public:
    int find(int i,int j,vector<int>& nums,vector<int>&dp){
        dp[i]=nums[i];
        if (i + 1 <= j)
            dp[i + 1] = max(nums[i], nums[i + 1]);
        for(int k=i+2;k<=j;k++){
            int pick=nums[k];
            if(k>1) pick+=dp[k-2];
            int notpick=dp[k-1];
            dp[k]=max(pick,notpick);
        }
        return dp[j];
    }
    
    int rob(vector<int>& nums) {
        int n =nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = find(0, n - 2, nums, dp1); // Exclude last house
        int case2 = find(1, n - 1, nums, dp2); // Exclude first house

        return max(case1,case2);

    }
};