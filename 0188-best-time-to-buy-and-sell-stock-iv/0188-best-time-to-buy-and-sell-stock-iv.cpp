class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // dp[ind][buy][cnt]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // Base cases are 0 (already initialized):
        // dp[n][buy][cnt] = 0  → no days left
        // dp[ind][buy][0] = 0  → no transactions left

        // Fill table backwards
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cnt = 1; cnt <= k; cnt++) {
                    if (buy == 0) {
                        dp[ind][buy][cnt] = max(
                            -prices[ind] + dp[ind + 1][1][cnt], // buy
                            dp[ind + 1][0][cnt]                // skip
                        );
                    } else {
                        dp[ind][buy][cnt] = max(
                            prices[ind] + dp[ind + 1][0][cnt - 1], // sell
                            dp[ind + 1][1][cnt]                    // skip
                        );
                    }
                }
            }
        }

        return dp[0][0][k];
    }
};
