class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = 1e9; // Large value to indicate an impossible state

        // DP table to store the minimum coins required
        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        // Initialize dp for the first row
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) {
                dp[0][t] = t / coins[0]; // Minimum coins to make `t` with `coins[0]`
            }
        }

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                int notTake = dp[ind - 1][t]; // Exclude the current coin
                int take = INF;
                if (t >= coins[ind]) { // Include the current coin if possible
                    take = 1 + dp[ind][t - coins[ind]];
                }
                dp[ind][t] = min(take, notTake);
            }
        }

        // Get the result from dp[n-1][amount]
        int ans = dp[n - 1][amount];
        return (ans >= INF) ? -1 : ans;
    }
};
