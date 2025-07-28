class Solution {
public:
     int maxOr = 0, count = 0;

    void dfs(int index, int currOr, vector<int>& nums) {
        if (index == nums.size()) {
            if (currOr == maxOr) count++;
            return;
        }

        // Include current element
        dfs(index + 1, currOr | nums[index], nums);

        // Exclude current element
        dfs(index + 1, currOr, nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // Step 1: Compute the maximum OR possible across all subsets
        for (int num : nums)
            maxOr |= num;

        // Step 2: Count how many subsets give that OR
        dfs(0, 0, nums);

        return count;
    }
};