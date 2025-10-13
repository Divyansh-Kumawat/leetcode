class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[ind][buy][cnt]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base case already initialized to 0 (no profit if cnt=0 or ind=n)

        // Fill table from back to front
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cnt = 1; cnt <= 2; cnt++) {
                    if (buy == 0) {
                        dp[ind][buy][cnt] = max(
                            -prices[ind] + dp[ind + 1][1][cnt],
                            dp[ind + 1][0][cnt]
                        );
                    } else {
                        dp[ind][buy][cnt] = max(
                            prices[ind] + dp[ind + 1][0][cnt - 1],
                            dp[ind + 1][1][cnt]
                        );
                    }
                }
            }
        }

        // Final answer: starting at day 0, can buy, with 2 transactions left
        return dp[0][0][2];
    }
};
