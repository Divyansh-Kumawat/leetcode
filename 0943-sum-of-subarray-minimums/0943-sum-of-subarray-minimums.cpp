class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> ple(n), nle(n);
        stack<int> stk;

        // Find Previous Less Element for each index
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            ple[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        // Clear stack to reuse
        while (!stk.empty()) stk.pop();

        // Find Next Less Element for each index
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            nle[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        // Compute result
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            total = (total + (arr[i] * left % mod) * right % mod) % mod;
        }

        return (int)total;
    }
};
