class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            } else if (ch == ')') {
                low--;
                high--;
            } else if (ch == '*') {
                low--;     // treat '*' as ')'
                high++;    // treat '*' as '('
            }
            if (high < 0) return false; // Too many ')'
            if (low < 0) low = 0;       // Can't have negative open
        }
        return low == 0;
    }
};
