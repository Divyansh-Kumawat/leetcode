class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string result = "";
        
        // Edge case: if k equals the number of digits, return "0"
        if (num.size() == k) {
            return "0";
        }

        // Iterate through each digit in the input string
        for (char digit : num) {
            // Remove the last digit in result if it's greater than the current digit and we still have k removals left
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit); // Add the current digit to the result
        }

        // If k is still greater than 0, remove the last k digits
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);

        // If the result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};