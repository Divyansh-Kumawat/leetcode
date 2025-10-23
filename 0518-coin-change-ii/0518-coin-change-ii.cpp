class Solution {
public:
    // int ways(vector<int>& coins,int ind,int amount,vector<vector<int>> &dp){  
    //     if(ind==0){
    //        return amount%coins[ind]==0;
    //     }
    //     if(dp[ind][amount]!=-1) return dp[ind][amount];
    //     int notpick=ways(coins,ind-1,amount,dp);
    //     int pick=0;
    //     if(amount >=coins[ind]){
    //         pick=ways(coins,ind,amount-coins[ind],dp);
    //     }
    //     return dp[ind][amount]=pick+notpick;

    // }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) dp[0][i] = 1;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                long long notpick=dp[ind-1][target];
                long long pick=0;
                if(target>=coins[ind]){
                    pick=dp[ind][target-coins[ind]];
                }
                dp[ind][target]=pick+notpick%MOD;
            }
        }
        return (int) dp[n-1][amount];

        // return ways(coins,n-1,amount,dp);
    }
};