class Solution {
public:
    // int maxprofit(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp){
    //     if(ind==prices.size()){
    //         return 0;
    //     }
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     int profit=0;
    //     if(!buy){
    //          profit=max(-prices[ind]+maxprofit(ind+1,1,prices,dp),
    //                         maxprofit(ind+1,0,prices,dp));
    //     }
    //     else{
    //          profit=max(prices[ind]+maxprofit(ind+1,0,prices,dp), 
    //                         maxprofit(ind +1,1,prices,dp));
    //     }
    //     return dp[ind][buy]=profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // Base case: dp[n][0] = dp[n][1] = 0 already initialized

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (!buy) {
                    // Option 1: Buy at this index -> move to state 'buy=1'
                    // Option 2: Skip buying
                    profit = max(-prices[ind] + dp[ind + 1][1],
                                 dp[ind + 1][0]);
                } else {
                    // Option 1: Sell at this index -> move to state 'buy=0'
                    // Option 2: Skip selling
                    profit = max(prices[ind] + dp[ind + 1][0],
                                 dp[ind + 1][1]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][0]; // start from index 0 with buy = 0 (we can buy)


    }
};