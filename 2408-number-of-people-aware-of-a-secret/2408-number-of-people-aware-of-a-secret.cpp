class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);  // dp[i] = number of people who learn on day i
        dp[1] = 1;

        long long sharing = 0;  // active sharers at a given day

        for (int day = 2; day <= n; day++) {
            // People who just become eligible to share
            if (day - delay >= 1) {
                sharing = (sharing + dp[day - delay]) % MOD;
            }
            // People who forget today (stop sharing)
            if (day - forget >= 1) {
                sharing = (sharing - dp[day - forget] + MOD) % MOD;
            }
            // New people who learn today
            dp[day] = sharing;
        }

        // Count people who still remember on day n
        long long ans = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) ans = (ans + dp[day]) % MOD;
        }
        return ans;
    }
};

