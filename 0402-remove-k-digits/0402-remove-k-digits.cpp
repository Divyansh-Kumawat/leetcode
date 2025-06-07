class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && k > 0 && stk.top() > num[i]) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;

        res = res.substr(i);
        return res.empty() ? "0" : res;
            
    }
};