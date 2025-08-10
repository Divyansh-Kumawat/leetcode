class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9; 
        vector<int> dp(amount + 1, INF);
        dp[0] = 0; // 0 coins to make 0 amount

        for (int coin : coins) {
            for (int amt = coin; amt <= amount; amt++) {
                dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
            }
        }

        return (dp[amount] >= INF) ? -1 : dp[amount];
    }
};
