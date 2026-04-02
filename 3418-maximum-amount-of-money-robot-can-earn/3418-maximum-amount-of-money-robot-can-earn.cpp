class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

    int m = coins.size();
    int n = coins[0].size();
    
    // dp[i][j][k]: max coins at (i,j) using k neutralizations
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
    
    // Initialize starting cell (0,0)
    for (int k = 0; k < 3; k++) {
        if (coins[0][0] >= 0) {
            dp[0][0][k] = coins[0][0];
        } else {
            if (k > 0) dp[0][0][k] = 0; // neutralize
            else dp[0][0][k] = coins[0][0];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                
                if (i == 0 && j == 0) continue;
                
                int val = coins[i][j];
                
                // From top or left with same k
                int bestPrev = INT_MIN;
                if (i > 0) bestPrev = max(bestPrev, dp[i-1][j][k]);
                if (j > 0) bestPrev = max(bestPrev, dp[i][j-1][k]);
                
                // Case 1: take value normally
                if (bestPrev != INT_MIN) {
                    dp[i][j][k] = max(dp[i][j][k], bestPrev + val);
                }
                
                // Case 2: neutralize (only if negative and k > 0)
                if (val < 0 && k > 0) {
                    int bestPrevK1 = INT_MIN;
                    if (i > 0) bestPrevK1 = max(bestPrevK1, dp[i-1][j][k-1]);
                    if (j > 0) bestPrevK1 = max(bestPrevK1, dp[i][j-1][k-1]);
                    
                    if (bestPrevK1 != INT_MIN) {
                        dp[i][j][k] = max(dp[i][j][k], bestPrevK1);
                    }
                }
            }
        }
    }
    
    return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});

    }
};