class Solution {
public:
    bool match(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // both string and pattern finished
        if (i < 0 && j < 0) return true;

        // string finished but pattern left
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        // pattern finished but string left
        if (i >= 0 && j < 0) return false;

        // check dp
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        // character matches or '?'
        if (s[i] == p[j] || p[j] == '?') {
            ans = match(i - 1, j - 1, s, p, dp);
        }
        else if (p[j] == '*') {
            ans = match(i - 1, j, s, p, dp)   // '*' matches one char
               || match(i, j - 1, s, p, dp); // '*' matches empty
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return match(n - 1, m - 1, s, p, dp);
    }
};
