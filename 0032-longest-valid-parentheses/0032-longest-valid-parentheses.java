class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1); // Base index for valid substring calculation
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i); // Store the index of '('
            } else {
                stack.pop(); // Try to match ')'
                if (stack.isEmpty()) {
                    stack.push(i); // Update base index
                } else {
                    maxLen = Math.max(maxLen, i - stack.peek()); // Compute valid length
                }
            }
        }
        return maxLen;
    }
}