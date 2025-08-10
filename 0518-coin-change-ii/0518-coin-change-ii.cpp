class Solution {
public:
    int value(vector<int>& coins,int ind,int amount,vector<vector<int>>& dp){
        if(ind==0){
            return amount% coins[ind]==0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notpick=value(coins,ind-1,amount,dp);
        int pick=0;
        if(coins[ind]<=amount) pick=value(coins,ind,amount-coins[ind],dp);
        return dp[ind][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return value(coins,n-1,amount,dp);
    }
};