class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total = 0;

        // Iterate over all starting points
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};

            // Expand substring ending at j
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mx = 0, mn = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        mx = max(mx, freq[k]);
                        mn = min(mn, freq[k]);
                    }
                }
                total += (mx - mn);
            }
        }
        return total;
    }
};
